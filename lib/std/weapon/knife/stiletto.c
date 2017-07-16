#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("thin stiletto");
  SetId( ({ "stiletto", "knife" }) );
  SetAdjectives( ({ "thin", "pointy", "stiletto" }) );
  SetShort("a thin stiletto");
  SetLong(
    "The blade on this stiletto is short "
    "and extremly pointy and very sturdy."
  );
  SetClass(9);
  SetDamagePoints(600);
  SetValue(200);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(250);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 0,
    "weapon smithing" : 1,
  ]) );
  SetRepairDifficulty(12);
}
