#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ITEM;
static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({"axe"}) );
  SetShort("a bony axe");
  SetLong("This axe gleams with fineness.  The handle is long and made "
  "of sturdy bone.  The blade itself, is thick and shines with sharpness.  "
  "It doesn't seem to be used a lot but it is chipped in the corner of the "
  "blade which would make this axe cause more pain than it should.");
  SetClass(16);
  SetAdjectives( ({"bony"}) );
  SetValue(400);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("hack");
  SetDamagePoints(750);
  SetMaterial( ({ "natural","metal" }) );
  SetRepairSkills( ([
  "metal working" : 10,
  "weapon smithing" : 10,
  ]) );
  SetRepairDifficulty(10);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:16:37 2000. */