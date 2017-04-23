#include	"PluginSDK.h"
#include	<Python.h>
#include	"LibPython.h"
#include	"Helper.h"
#include	"Script.h"
#include	"Callback.h"
#include	"CreateConsole.h"
#include	"spdlog\spdlog.h"

PyThreadState*			pMainThreadState;
PyInterpreterState*		interpreterState;
std::vector<t_script>	ScriptList;
IMenu*					MainMenu;
IMenuOption*			DebugConsole;
bool					DebugConsoleIsOpen = FALSE;

PLUGIN_API void GameUpdate();

#pragma warning(disable:4996)


PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
	PluginSDKSetup(PluginSDK);

	GGame->PrintChat("Lib python loaded");
	//RedirectIOToConsole();

	auto console = spdlog::stdout_color_mt("console");
	console->set_pattern("%H:%M - [%l] [LibPython] %v");
	console->set_level(spdlog::level::debug);

	PythonInitialize();
	LoadAllScript(ScriptList);

	pMainThreadState = PyEval_SaveThread();

	CreateMyMenu();
	//CallPythonOnLoad(ScriptList);

	RegisterCallback();
	GEventManager->AddEventHandler(kEventOnGameUpdate, GameUpdate);
}

void	CreateMyMenu()
{
	std::vector<t_script>::iterator it;

	MainMenu = GPluginSDK->AddMenu("LibPython Menu");
	IMenu *ScriptMenu = MainMenu->AddMenu(">> Scripts <<");
	IMenu *DevMenu = MainMenu->AddMenu(">> Developers Options <<");
	for (it = ScriptList.begin(); it < ScriptList.end(); it++)
		it->MenuLoad = ScriptMenu->CheckBox(it->Name.c_str(), FALSE);
	DebugConsole = DevMenu->CheckBox("Show debug console", FALSE);
}

PLUGIN_API void GameUpdate()
{
	std::vector<t_script>::iterator it;

	CallPythonMethod(ScriptList, "OnGameUpdate", NULL);

	if (DebugConsole->Enabled() && !DebugConsoleIsOpen )
	{
		DebugConsoleIsOpen = TRUE;
		RedirectIOToConsole();
	}
	for (it = ScriptList.begin(); it < ScriptList.end(); it++)
	{
		if (it->MenuLoad->Enabled() && it->IsRunning == FALSE && it->Loaded == FALSE)
		{
				it->IsRunning = TRUE;
				PyEval_RestoreThread(pMainThreadState);
				LoadScript(*it);
				pMainThreadState = PyEval_SaveThread();
				if (it->Imported)
					CallPythonOnLoadSingle(*it);
		}
		else if (it->Imported && !it->MenuLoad->Enabled() && it->IsRunning && it->Loaded)
		{
			it->IsRunning = FALSE;
			CallPythonMethodSingle(*it, "OnUnload", NULL);
			it->Loaded = FALSE;
		}
	}
}

PLUGIN_API void OnUnload()
{
	UnregisterCallback();
	GEventManager->RemoveEventHandler(kEventOnGameUpdate, GameUpdate);

	CallPythonMethod(ScriptList, "OnUnload", NULL);
	closeAllThread(ScriptList);

	std::vector<t_script>::iterator it;
	for (it = ScriptList.begin(); it < ScriptList.end(); it++)
	{
		if (it->Imported)
			Py_DecRef(it->Module);
	}

	if (Py_IsInitialized())
	{
		PyEval_RestoreThread( pMainThreadState ) ;
		PyImport_Cleanup();
		Py_Finalize();
	}

	MainMenu->Remove();

	GGame->PrintChat("Lib python unloaded");
}