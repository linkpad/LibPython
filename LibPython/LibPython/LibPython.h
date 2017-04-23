#ifndef LIBPYTHON_H_
#define LIBPYTHON_H_

#include	<Python.h>
#include	<vector>
#include	"Script.h"

extern PyThreadState*			pMainThreadState;
extern PyInterpreterState*		interpreterState;
extern std::vector<t_script>	ScriptList;

void	CreateMyMenu();

#endif // !LIBPYTHON_H_
