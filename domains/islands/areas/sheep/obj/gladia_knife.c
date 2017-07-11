#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("blood-stained knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "blood", "stained" }) );
  SetShort("a blood-stained knife");
  SetLong(
    "This black-handled knife has a faint coppery stain along the edge. It can only have been "
    "used for one thing: killing a living creature."
  );
  SetClass(15);
  SetDamagePoints(1200);
  SetValue(250);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(15);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "weapon smithing" : 1,
    "metal working" : 1,
  ]) );
  SetRepairDifficulty(18);
}
