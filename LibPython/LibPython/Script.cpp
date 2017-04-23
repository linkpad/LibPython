#include	"PluginSDK.h"
#include	"Script.h"
#include	"Helper.h"
#include	"Utils.h"
#include	"LibPython.h"
#include	"spdlog\spdlog.h"

void	LoadScript(t_script &script)
{
	PyObject	*pname;
	PyObject	*pmodule;

	auto console = spdlog::get("console");
	if (script.Imported && script.Module != NULL)
	{
		PyImport_ReloadModule(script.Module);
		console->debug("Successfully reloaded {} script.", script.Name);
	}
	else
	{
		pname = PyUnicode_DecodeFSDefault(script.Name.c_str());
		//pname = PyString_FromString(script.Name.c_str());
		pmodule = PyImport_Import(pname);
		Py_DecRef(pname);
		if (pmodule == NULL)
		{
			script.Imported = FALSE;
			PythonErrorHandling();
		}
		else
		{
			script.Module = pmodule;
			script.Imported = TRUE;
		}
		console->debug("Successfully imported {} script.", script.Name);
	}
}

void	LoadAllScript(std::vector<t_script> &ScriptList)
{
	std::string							Directory;
	std::vector<std::string>			fileName;
	std::vector<std::string>::iterator	it;

	GPluginSDK->GetBaseDirectory(Directory);
	Directory += "\\Plugins\\LibPython";
	fileName = get_all_files_names_within_folder(Directory);

	auto console = spdlog::get("console");
	for (it = fileName.begin(); it < fileName.end(); it++)
	{
		console->debug("found {} addons.", *it);
		t_script	script;
		script.Name = *it;
		script.Loaded = FALSE;
		script.IsRunning = FALSE;
		script.Imported = FALSE;
		//LoadScript(script);
		console->debug("Try to push {} module in scriptList.", script.Name);
		ScriptList.push_back(script);
	}
	console->debug("All module pushed in scriptList.");
}

void	CallPythonMethod(std::vector<t_script> &ScriptList, const char *method, PyObject *args)
{
	std::vector<t_script>::iterator it;

	PyEval_RestoreThread(pMainThreadState);
	for (it = ScriptList.begin(); it < ScriptList.end(); it++)
	{
		if (it->Loaded)
			PythonCallFunction(it->Module, method, args);
	}
	pMainThreadState = PyEval_SaveThread();
}

void	CallPythonMethodSingle(t_script &script, const char *method, PyObject *args)
{
	PyEval_RestoreThread(pMainThreadState);
	if (script.Loaded && script.Imported)
		PythonCallFunction(script.Module, method, args);
	pMainThreadState = PyEval_SaveThread();
}

void	CallPythonMethodThread(std::vector<t_script> &ScriptList, const char *method, PyObject *args)
{
	std::vector<t_script>::iterator it;

	for (it = ScriptList.begin(); it < ScriptList.end(); it++)
	{
		if (it->Imported)
		{
			t_function	*Function;
			Function = new t_function();
			Function->Name = method;
			Function->Module = it->Module;
			Function->ThreadState = pMainThreadState;
			Function->interpreterState = interpreterState;
			Function->Runned = NULL;
			it->HandleOnLoad = (HANDLE)_beginthreadex(0, 0, ThreadCall, Function, 0, 0);
		}
	}
}

void	CallPythonOnLoad(std::vector<t_script> &ScriptList)
{
	std::vector<t_script>::iterator it;

	auto console = spdlog::get("console");
	for (it = ScriptList.begin(); it < ScriptList.end(); it++)
	{
		if (it->Imported)
		{
			console->debug("Call OnLoad for {} script.", it->Name);
			t_function	*Function;
			Function = new t_function();
			Function->Name = "OnLoad";
			Function->Module = it->Module;
			Function->ThreadState = pMainThreadState;
			Function->interpreterState = interpreterState;
			Function->Runned = &(it->Loaded);
			it->HandleOnLoad = (HANDLE)_beginthreadex(0, 0, ThreadCall, Function, 0, 0);
		}
	}
}

void	CallPythonOnLoadSingle(t_script &script)
{
	auto console = spdlog::get("console");

	console->debug("Call OnLoad for {} script.", script.Name);
	t_function	*Function;
	Function = new t_function();
	Function->Name = "OnLoad";
	Function->Module = script.Module;
	Function->ThreadState = pMainThreadState;
	Function->interpreterState = interpreterState;
	Function->Runned = &(script.Loaded);
	script.HandleOnLoad = (HANDLE)_beginthreadex(0, 0, ThreadCall, Function, 0, 0);
}