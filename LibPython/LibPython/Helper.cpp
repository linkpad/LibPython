#include	"PluginSDK.h"
#include	"Helper.h"
#include	"SDKWrapper.h"
#include	"Utils.h"
#include	"Script.h"
#include	"LibPython.h"
#include	"spdlog\spdlog.h"


#pragma warning(disable:4996)

unsigned __stdcall	ThreadCall(void *tmp)
{
	t_function	*Function;
	PyThreadState *pThreadState, *pThreadStateSub;

	Function = (t_function*)tmp;

	pThreadState = PyThreadState_New(Function->interpreterState);
	PyEval_RestoreThread(pThreadState);

	pThreadStateSub = Py_NewInterpreter();
	assert(pThreadStateSub != NULL);
	if (pThreadStateSub != NULL)
	{
		PythonCallFunction(Function->Module, Function->Name.c_str(), NULL);
		Py_EndInterpreter(pThreadStateSub);
	}
	PyThreadState_Swap(pThreadState);
	PyEval_SaveThread();
	if (Function->Runned != NULL)
		*(Function->Runned) = TRUE;
	return (NULL);
}

void	PythonCallFunction(PyObject *pmodule, const char *name, PyObject *args)
{
	PyObject	*pret, *pfunc;
	if (PyObject_HasAttrString((PyObject *)pmodule, name) == 1)
	{
		pfunc = PyObject_GetAttrString((PyObject *)pmodule, name);
		if (pfunc != NULL)
		{
			if (PyCallable_Check(pfunc))
			{
				pret = PyObject_CallObject(pfunc, args);
				if (pret == NULL)
					PythonErrorHandling();
				else
					Py_DecRef(pret);
			}
			else
				PythonErrorHandling();
			Py_DecRef(pfunc);
		}
	}
}

void	PythonErrorHandling()
{
	if (PyErr_Occurred())
	{
		auto console = spdlog::get("console");
		console->error("Python error : ");
		PyErr_PrintEx(1);
	}
}

void	PythonInitialize()
{
	std::string	Directory;

	PyImport_AppendInittab("SDK", &initSDK);
	Py_Initialize();
	PyEval_InitThreads();
	GPluginSDK->GetBaseDirectory(Directory);
	Directory = Directory + "\\Plugins\\LibPython;" + Directory + "\\Plugins\\LibPython\\Lib";
	wchar_t *Path = Py_DecodeLocale(Directory.c_str(), NULL);
	PySys_SetPath(Path);
	PyImport_ImportModule("SDK");

	pMainThreadState = PyThreadState_Get();
	interpreterState = pMainThreadState->interp;
}


void	closeSingleThread(HANDLE handle)
{
	DWORD dwResult;
	if (handle != NULL)
	{
		dwResult = WaitForSingleObject(handle, 1000);
		if (dwResult == WAIT_OBJECT_0)
			CloseHandle(handle);
		else if (dwResult == WAIT_TIMEOUT)
		{
			TerminateThread(handle, 1);
			while ((dwResult = WaitForSingleObject(handle, 1000)) != WAIT_OBJECT_0);
			if (dwResult == WAIT_OBJECT_0)
				CloseHandle(handle);
		}
	}
}

void	closeAllThread(std::vector<t_script> &ScriptList)
{
	std::vector<t_script>::iterator it;
	for (it = ScriptList.begin(); it < ScriptList.end(); it++)
	{
		if (it->Loaded)
		{
			it->Loaded = FALSE;
			closeSingleThread(it->HandleOnLoad);
			closeSingleThread(it->HandleOnRender);
		}
	}
}