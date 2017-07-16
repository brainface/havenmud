#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("blood red sword");
  SetShort("a blood red sword");
  SetLong(
    "This broad sword has a blade of a reddish metal. "
    "It looks wickedly sharp."
  );
  SetId( ({ "sword", }) );
  SetAdjectives( ({ "blood", "red" }) );
  SetClass(14);
  SetDamagePoints(2000);
  SetRepairDifficulty(14);
  SetValue(250);
  SetMass(65);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "weapon smithing" : 8,
    "metal working"   : 8,
     ]) );
}
