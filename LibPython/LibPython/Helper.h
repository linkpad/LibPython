#ifndef HELPER_H_
#define HELPER_H_

#include	<Python.h>
#include	<Windows.h>
#include	<process.h>
#include	<vector>
#include	"Script.h"

unsigned __stdcall	ThreadCall(void *tmp);
void	PythonCallFunction(PyObject *pmodule, const char *name, PyObject *args);
void	PythonErrorHandling();
void	PythonInitialize();
void	closeSingleThread(HANDLE handle);
void	closeAllThread(std::vector<t_script> &ScriptList);

#endif // !HELPER_H_
