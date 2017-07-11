//-- Torak@Haven --//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("pike");
  SetHands(2);
  SetId( ({ "pike", "long pike" }) );
  SetShort("a long pike");
  SetLong("This pike was crafted of the finest wood of the swamps, "
          "meaning it was in bad shape when it was done.  It is "
          "the favored weapon of lizardmen, and can slice heads off "
          "in a quick action.");
  SetMass(150); 
  SetValue(150);
  SetDamagePoints(800);
  SetWeaponType("pole");
  SetDamageType(PIERCE);
  SetClass(14);
  SetVendorType(VT_WEAPON);
  SetMaterial("metal");
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "weapon smithing" : 5,
    "metal working"   : 5,
    "wood working"    : 5,
    ]) );
}
