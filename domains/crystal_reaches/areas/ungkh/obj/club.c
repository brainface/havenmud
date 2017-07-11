//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a gigantic club");
  SetId( ({ "club" }) );
  SetAdjectives( ({ "gigantic" }) );
  SetLong(
     "This club is nearly as tall as a full-grown elf and "
     "has seen more than a few fights, from the looks of the "
     "notched and rubbed end."
  );
  SetClass(5);
  SetDamagePoints(600);
    SetValue(1200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("club");
  SetMass(275);
  SetMaterial( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetVendorType(VT_WEAPON);
}
