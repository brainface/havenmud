//Samah@Haven
//20040911
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("wooden sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ 
     "small",
     "wooden",
     "wood" 
  }) );
  SetShort("a splintered wooden sword");
  SetLong(
     "The sword is little more then a toy. It is made "
     "of a light wood and has seen a great deal of misuse. A "
     "large crack runs down the length of the blade."
  );
  SetClass(5);
  SetDamagePoints(400);
  SetValue(10);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(55);
  SetMaterial("wood");
  SetRepairDifficulty(5);
  SetVendorType(VT_WEAPON);
}

/** Approved by Laoise at Sat Sep 11 20:28:19 2004. **/
