// An old pole used for fishing and sold at the shop at 
// Platypus Bay. 
// Urien@Haven 06JUL08

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_POLE;

static void create() {
  pole::create();
  SetKeyName("old fishing pole");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "wood working" : 1,
    ]) );
  SetMaterial( ({ "wood" }) );
  SetShort("an old fishing pole");
  SetId( ({ "pole" }) );
  SetAdjectives( ({ "fishing", "old" }) );
  SetLong(
          "This old pole appears to have been whittled down from an "
          "old stick. It has three brass rings which holds the fishing "
          "line from separating. On the end of the line is a lead sinker "
          "and a brass hook."
          );
  SetStrength(50);
  SetChance(40);
  SetVendorType(VT_FISHING);
  SetDamagePoints(100);
  SetClass(8);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMass(70);
  SetValue(20);
  }

