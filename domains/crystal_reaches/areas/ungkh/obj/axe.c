//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("battleaxe");
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(12);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
   ]) );
  SetMaterial("metal");
  SetShort("a large battleaxe");
  SetId( ({ "axe", "battleaxe" }) );
  SetHands(2);
  SetAdjectives( ({ "large", "battle" }) );
  SetLong("This is an enormous battleaxe, built to sever "
         "limbs from bodies and heads from necks with ease.");
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2000);
  SetClass(20);
  SetMass(275);
  SetValue(300);
  }
