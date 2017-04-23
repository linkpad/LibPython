#ifndef SDKWRAPPER_H_
#define SDKWRAPPER_H_

#include	<Python.h>
#include	"PluginSDK.h"

PyMODINIT_FUNC initSDK(void);

typedef enum _PyBindGenWrapperFlags {
	PYBINDGEN_WRAPPER_FLAG_NONE = 0,
	PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED = (1 << 0),
} PyBindGenWrapperFlags;

typedef struct {
	PyObject_HEAD
		Vec2 *obj;
	PyBindGenWrapperFlags flags : 8;
} PyVec2;


extern PyTypeObject PyVec2_Type;


typedef struct {
	PyObject_HEAD
		Vec3 *obj;
	PyBindGenWrapperFlags flags : 8;
} PyVec3;


extern PyTypeObject PyVec3_Type;


typedef struct {
	PyObject_HEAD
		Vec4 *obj;
	PyBindGenWrapperFlags flags : 8;
} PyVec4;


extern PyTypeObject PyVec4_Type;


typedef struct {
	PyObject_HEAD
		IUnit *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIUnit;


extern PyTypeObject PyIUnit_Type;


typedef struct {
	PyObject_HEAD
		CastedSpell *obj;
	PyBindGenWrapperFlags flags : 8;
} PyCastedSpell;


extern PyTypeObject PyCastedSpell_Type;


typedef struct {
	PyObject_HEAD
		LastCastedSpellArgs *obj;
	PyBindGenWrapperFlags flags : 8;
} PyLastCastedSpellArgs;


extern PyTypeObject PyLastCastedSpellArgs_Type;


typedef struct {
	PyObject_HEAD
		NavigationPath *obj;
	PyBindGenWrapperFlags flags : 8;
} PyNavigationPath;


extern PyTypeObject PyNavigationPath_Type;


typedef struct {
	PyObject_HEAD
		UnitDash *obj;
	PyBindGenWrapperFlags flags : 8;
} PyUnitDash;


extern PyTypeObject PyUnitDash_Type;


typedef struct {
	PyObject_HEAD
		OnTeleportArgs *obj;
	PyBindGenWrapperFlags flags : 8;
} PyOnTeleportArgs;


extern PyTypeObject PyOnTeleportArgs_Type;


typedef struct {
	PyObject_HEAD
		AdvPredictionInput *obj;
	PyBindGenWrapperFlags flags : 8;
} PyAdvPredictionInput;


extern PyTypeObject PyAdvPredictionInput_Type;


typedef struct {
	PyObject_HEAD
		AdvPredictionOutput *obj;
	PyBindGenWrapperFlags flags : 8;
} PyAdvPredictionOutput;


extern PyTypeObject PyAdvPredictionOutput_Type;


typedef struct {
	PyObject_HEAD
		InterruptibleSpell *obj;
	PyBindGenWrapperFlags flags : 8;
} PyInterruptibleSpell;


extern PyTypeObject PyInterruptibleSpell_Type;


typedef struct {
	PyObject_HEAD
		GapCloserSpell *obj;
	PyBindGenWrapperFlags flags : 8;
} PyGapCloserSpell;


extern PyTypeObject PyGapCloserSpell_Type;


typedef struct {
	PyObject_HEAD
		ItemData *obj;
	PyBindGenWrapperFlags flags : 8;
} PyItemData;


extern PyTypeObject PyItemData_Type;


typedef struct {
	PyObject_HEAD
		JungleNotifyData *obj;
	PyBindGenWrapperFlags flags : 8;
} PyJungleNotifyData;


extern PyTypeObject PyJungleNotifyData_Type;


typedef struct {
	PyObject_HEAD
		HeroMastery *obj;
	PyBindGenWrapperFlags flags : 8;
} PyHeroMastery;


extern PyTypeObject PyHeroMastery_Type;


typedef struct {
	PyObject_HEAD
		ISpellBook *obj;
	PyBindGenWrapperFlags flags : 8;
} PyISpellBook;


extern PyTypeObject PyISpellBook_Type;


typedef struct {
	PyObject_HEAD
		IFont *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIFont;


extern PyTypeObject PyIFont_Type;


typedef struct {
	PyObject_HEAD
		ITexture *obj;
	PyBindGenWrapperFlags flags : 8;
} PyITexture;


extern PyTypeObject PyITexture_Type;


typedef struct {
	PyObject_HEAD
		IRender *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIRender;


extern PyTypeObject PyIRender_Type;


typedef struct {
	PyObject_HEAD
		ITargetSelector *obj;
	PyBindGenWrapperFlags flags : 8;
} PyITargetSelector;


extern PyTypeObject PyITargetSelector_Type;


typedef struct {
	PyObject_HEAD
		IPrediction *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIPrediction;


extern PyTypeObject PyIPrediction_Type;


typedef struct {
	PyObject_HEAD
		IMenuOption *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIMenuOption;


extern PyTypeObject PyIMenuOption_Type;


typedef struct {
	PyObject_HEAD
		IMenu *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIMenu;


extern PyTypeObject PyIMenu_Type;


typedef struct {
	PyObject_HEAD
		IHealthPrediction *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIHealthPrediction;


extern PyTypeObject PyIHealthPrediction_Type;


typedef struct {
	PyObject_HEAD
		ISpell2 *obj;
	PyBindGenWrapperFlags flags : 8;
} PyISpell2;


extern PyTypeObject PyISpell2_Type;


typedef struct {
	PyObject_HEAD
		IOrbwalking *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIOrbwalking;


extern PyTypeObject PyIOrbwalking_Type;


typedef struct {
	PyObject_HEAD
		IInventoryItem *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIInventoryItem;


extern PyTypeObject PyIInventoryItem_Type;


typedef struct {
	PyObject_HEAD
		IMissileData *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIMissileData;


extern PyTypeObject PyIMissileData_Type;


typedef struct {
	PyObject_HEAD
		INavMesh *obj;
	PyBindGenWrapperFlags flags : 8;
} PyINavMesh;


extern PyTypeObject PyINavMesh_Type;


typedef struct {
	PyObject_HEAD
		IUtility *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIUtility;


extern PyTypeObject PyIUtility_Type;


typedef struct {
	PyObject_HEAD
		IPluginSDK *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIPluginSDK;


extern PyTypeObject PyIPluginSDK_Type;


typedef struct {
	PyObject_HEAD
		IEntityList *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIEntityList;


extern PyTypeObject PyIEntityList_Type;


typedef struct {
	PyObject_HEAD
		IGame *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIGame;


extern PyTypeObject PyIGame_Type;


typedef struct {
	PyObject_HEAD
		IDamage *obj;
	PyBindGenWrapperFlags flags : 8;
} PyIDamage;


extern PyTypeObject PyIDamage_Type;

#endif // !SDKWRAPPER_H_

