#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("blood sword");
  SetId( ({ "sword", }) );
  SetAdjectives( ({ "blood", "red" }) );
  SetShort("a blood red sword");
  SetLong(
    "This broad sword has a blade of a reddish metal. "
    "It looks wickedly sharp."
  );
  SetClass(14);
  SetDamagePoints(2000);
  SetValue(250);
  SetMass(65);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "weapon smithing" : 8,
    "metal working"   : 8,
  ]) );
  SetRepairDifficulty(14);
}
