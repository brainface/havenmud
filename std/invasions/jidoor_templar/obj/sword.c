/*  A buff slashing weapon for certain paladin-oriented people */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("longsword");
  SetShort("a heavy longsword");
  SetId( ({ "sword", "longsword" }) );
  SetAdjectives( ({ "heavy" }) );
  SetLong(
    "This heavy longsword was designed for slaughter. "
    "There is little to suggest it was made for any "
    "purpose except that of swift killing."
  );
  SetMass(120);
  SetValue(200);
  SetClass(15);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
  ]) );
  SetProperty("history", "This sword was fashioned for the Paladins of Kylin.");
}
