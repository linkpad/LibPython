#include	"PluginSDK.h"
#include	"LibPython.h"
#include	"Script.h"
#include	"Callback.h"
#include	"SDKWrapper.h"

void	RegisterCallback()
{
	GEventManager->AddEventHandler(kEventOnRender, OnRender);
	GEventManager->AddEventHandler(kEventOnRenderBehindHud, OnRenderBehindHud);

	//ORBWALK
	//GEventManager->AddEventHandler(kEventOrbwalkBeforeAttack, OnOrbwalkBeforeAttack);
	//GEventManager->AddEventHandler(kEventOrbwalkOnAttack, OnOrbwalkOnAttack);
	//GEventManager->AddEventHandler(kEventOrbwalkAfterAttack, OnOrbwalkAfterAttack);
	//GEventManager->AddEventHandler(kEventOrbwalkTargetChange, OnOrbwalkTargetChange);
	//GEventManager->AddEventHandler(kEventOrbwalkNonKillableMinion, OnOrbwalkNonKillableMinion);
	//GEventManager->AddEventHandler(kEventOrbwalkFindTarget, OnOrbwalkFindTarget);

	GEventManager->AddEventHandler(kEventOnGameEnd, OnGameEnd);

	GEventManager->AddEventHandler(kEventOnCreateObject, OnCreateObject);
	GEventManager->AddEventHandler(kEventOnDestroyObject, OnDestroyObject);
	GEventManager->AddEventHandler(kEventOnUnitDeath, OnUnitDeath);
	GEventManager->AddEventHandler(kEventOnBuffAdd, OnBuffAdd);
	GEventManager->AddEventHandler(kEventOnBuffRemove, OnBuffRemove);
	GEventManager->AddEventHandler(kEventOnDash, OnDash);
}

void	UnregisterCallback()
{
	GEventManager->RemoveEventHandler(kEventOnRender, OnRender);
	GEventManager->RemoveEventHandler(kEventOnRenderBehindHud, OnRenderBehindHud);

	//ORBWALK
	//GEventManager->RemoveEventHandler(kEventOrbwalkBeforeAttack, OnOrbwalkBeforeAttack);
	//GEventManager->RemoveEventHandler(kEventOrbwalkOnAttack, OnOrbwalkOnAttack);
	//GEventManager->RemoveEventHandler(kEventOrbwalkAfterAttack, OnOrbwalkAfterAttack);
	//GEventManager->RemoveEventHandler(kEventOrbwalkTargetChange, OnOrbwalkTargetChange);
	//GEventManager->RemoveEventHandler(kEventOrbwalkNonKillableMinion, OnOrbwalkNonKillableMinion);
	//GEventManager->RemoveEventHandler(kEventOrbwalkFindTarget, OnOrbwalkFindTarget);

	GEventManager->RemoveEventHandler(kEventOnGameEnd, OnGameEnd);

	GEventManager->RemoveEventHandler(kEventOnCreateObject, OnCreateObject);
	GEventManager->RemoveEventHandler(kEventOnDestroyObject, OnDestroyObject);
	GEventManager->RemoveEventHandler(kEventOnUnitDeath, OnUnitDeath);
	GEventManager->RemoveEventHandler(kEventOnBuffAdd, OnBuffAdd);
	GEventManager->RemoveEventHandler(kEventOnBuffRemove, OnBuffRemove);
	GEventManager->RemoveEventHandler(kEventOnDash, OnDash);
}

PLUGIN_EVENT(void)	OnRender()
{
	CallPythonMethod(ScriptList, "OnRender", NULL);
}

PLUGIN_EVENT(void)	OnRenderBehindHud()
{
	CallPythonMethod(ScriptList, "OnRenderBehindHud", NULL);
}

PLUGIN_EVENT(void)	OnOrbwalkBeforeAttack(IUnit* Object)
{
	PyObject *py_retval;
	IUnit *retval;
	PyIUnit *py_IUnit;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnOrbwalkBeforeAttack", pArgs);
}

PLUGIN_EVENT(void)	OnOrbwalkOnAttack(IUnit* Source, IUnit* Target)
{
	PyObject *py_retval, *py_retval2;
	IUnit *retval, *retval2;
	PyIUnit *py_IUnit, *py_IUnit2;
	PyObject *pArgs = PyTuple_New(2);

	retval = Source;
	retval2 = Target;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_IUnit2 = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit2->obj = retval2;
	py_IUnit2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	py_retval2 = Py_BuildValue((char *) "N", py_IUnit2);
	PyTuple_SetItem(pArgs, 0, py_retval);
	PyTuple_SetItem(pArgs, 1, py_retval2);
	CallPythonMethod(ScriptList, "OnOrbwalkOnAttack", pArgs);
}

PLUGIN_EVENT(void)	OnOrbwalkAfterAttack(IUnit* Source, IUnit* Target)
{
	PyObject *py_retval, *py_retval2;
	IUnit *retval, *retval2;
	PyIUnit *py_IUnit, *py_IUnit2;
	PyObject *pArgs = PyTuple_New(2);

	retval = Source;
	retval2 = Target;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_IUnit2 = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit2->obj = retval2;
	py_IUnit2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	py_retval2 = Py_BuildValue((char *) "N", py_IUnit2);
	PyTuple_SetItem(pArgs, 0, py_retval);
	PyTuple_SetItem(pArgs, 1, py_retval2);
	CallPythonMethod(ScriptList, "OnOrbwalkAfterAttack", pArgs);
}

PLUGIN_EVENT(void)	OnOrbwalkTargetChange(IUnit* Old, IUnit* New)
{
	PyObject *py_retval, *py_retval2;
	IUnit *retval, *retval2;
	PyIUnit *py_IUnit, *py_IUnit2;
	PyObject *pArgs = PyTuple_New(2);

	retval = Old;
	retval2 = New;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_IUnit2 = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit2->obj = retval2;
	py_IUnit2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	py_retval2 = Py_BuildValue((char *) "N", py_IUnit2);
	PyTuple_SetItem(pArgs, 0, py_retval);
	PyTuple_SetItem(pArgs, 1, py_retval2);
	CallPythonMethod(ScriptList, "OnOrbwalkTargetChange", pArgs);
}

PLUGIN_EVENT(void)	OnOrbwalkNonKillableMinion(IUnit* Object)
{
	PyObject *py_retval;
	IUnit *retval;
	PyIUnit *py_IUnit;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnOrbwalkNonKillableMinion", pArgs);
}

PLUGIN_EVENT(void)	OnOrbwalkFindTarget()
{
	CallPythonMethod(ScriptList, "OnOrbwalkFindTarget", NULL);
}

PLUGIN_EVENT(void)	OnGameEnd()
{
	CallPythonMethod(ScriptList, "OnGameEnd", NULL);
}

PLUGIN_EVENT(void)	OnCreateObject(IUnit* Object)
{
	PyObject *py_retval;
	IUnit *retval;
	PyIUnit *py_IUnit;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnCreateObject", pArgs);
}

PLUGIN_EVENT(void)	OnDestroyObject(IUnit* Object)
{
	PyObject *py_retval;
	IUnit *retval;
	PyIUnit *py_IUnit;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnDestroyObject", pArgs);
}

PLUGIN_EVENT(void)	OnUnitDeath(IUnit* Object)
{
	PyObject *py_retval;
	IUnit *retval;
	PyIUnit *py_IUnit;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnUnitDeath", pArgs);
}

PLUGIN_EVENT(void)	OnBuffAdd(IUnit* Object)
{
	PyObject *py_retval;
	IUnit *retval;
	PyIUnit *py_IUnit;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnBuffAdd", pArgs);
}

PLUGIN_EVENT(void)	OnBuffRemove(IUnit* Object)
{
	PyObject *py_retval;
	IUnit *retval;
	PyIUnit *py_IUnit;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_IUnit = PyObject_New(PyIUnit, &PyIUnit_Type);
	py_IUnit->obj = retval;
	py_IUnit->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_IUnit);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnBuffRemove", pArgs);
}

PLUGIN_EVENT(void)	OnDash(UnitDash *Object)
{
	PyObject *py_retval;
	UnitDash *retval;
	PyUnitDash *py_UnitDash;
	PyObject *pArgs = PyTuple_New(1);

	retval = Object;
	py_UnitDash = PyObject_New(PyUnitDash, &PyUnitDash_Type);
	py_UnitDash->obj = retval;
	py_UnitDash->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
	py_retval = Py_BuildValue((char *) "N", py_UnitDash);
	PyTuple_SetItem(pArgs, 0, py_retval);
	CallPythonMethod(ScriptList, "OnDash", pArgs);
}