#ifndef SCRIPT_H_
#define	SCRIPT_H_

#include	<windows.h>
#include	<string>
#include	<Python.h>
#include	"PluginSDK.h"

typedef struct	s_script
{
	std::string Name;
	IMenuOption*	MenuLoad;
	bool		IsRunning;
	bool		Imported;
	bool		Loaded;
	PyObject	*Module;
	HANDLE		HandleOnLoad;
	HANDLE		HandleOnRender;
	HANDLE		HandleOnUnload;
}				t_script;

typedef struct			s_function
{
	std::string			Name;
	PyObject			*Module;
	PyThreadState*		ThreadState;
	PyInterpreterState* interpreterState;
	bool				*Runned;
}						t_function;

void	LoadScript(t_script &script);
void	LoadAllScript(std::vector<t_script> &ScriptList);
void	CallPythonMethod(std::vector<t_script> &ScriptList, const char *method, PyObject *args);
void	CallPythonMethodThread(std::vector<t_script> &ScriptList, const char *method, PyObject *args);
void	CallPythonOnLoad(std::vector<t_script> &ScriptList);
void	CallPythonOnLoadSingle(t_script &script);
void	CallPythonMethodSingle(t_script &script, const char *method, PyObject *args);

#endif // !SCRIPT_H_
