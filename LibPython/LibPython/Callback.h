#ifndef CALLBACK_H_
#define CALLBACK_H_

#include	"PluginSDK.h"

void	RegisterCallback();
void	UnregisterCallback();

PLUGIN_EVENT(void)	OnRender();
PLUGIN_EVENT(void)	OnRenderBehindHud();

PLUGIN_EVENT(void)	OnOrbwalkBeforeAttack(IUnit* Object);
PLUGIN_EVENT(void)	OnOrbwalkOnAttack(IUnit* Source, IUnit* Target);
PLUGIN_EVENT(void)	OnOrbwalkAfterAttack(IUnit* Source, IUnit* Target);
PLUGIN_EVENT(void)	OnOrbwalkTargetChange(IUnit* Old, IUnit* New);
PLUGIN_EVENT(void)	OnOrbwalkNonKillableMinion(IUnit* Object);
PLUGIN_EVENT(void)	OnOrbwalkFindTarget();

PLUGIN_EVENT(void)	OnGameEnd();

PLUGIN_EVENT(void)	OnCreateObject(IUnit* Object);
PLUGIN_EVENT(void)	OnDestroyObject(IUnit* Object);
PLUGIN_EVENT(void)	OnUnitDeath(IUnit* Object);
PLUGIN_EVENT(void)	OnBuffAdd(IUnit* Object);
PLUGIN_EVENT(void)	OnBuffRemove(IUnit* Object);
PLUGIN_EVENT(void)	OnDash(UnitDash *Object);

#endif // !CALLBACK_H_
