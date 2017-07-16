#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("plastic feathermop");
  SetId( ({ "plastic", "feathermop", "mop" }) );
  SetAdjectives( ({ "plastic", "hard", "sharp", "large", "soft", }) );
  SetShort("a plastic feathermop");
  SetLong(
    "The feathermop is made of a hard plastic pole with a "
    "hidden very sharp metal point on one end and a large "
    "grouping of extremely soft feathers on the other. "
  );
  SetMass(5); 
  SetValue(100000);
  SetDamagePoints(5000);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(50);
  SetHands(1);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "plastic" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
    ]) );
  SetRepairDifficulty(200);
}
