#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;


static void create() {
  armour::create();
  SetKeyName("mithril gauntlets");
  SetId( ({ "gauntlets" }) );
  SetAdjectives( ({ "mithril" }) );
  SetShort("a pair of mithril gauntlets");
  SetLong("An energy glows off of the pair of mithril gauntlets.");
  SetVendorType(VT_ARMOUR);
  SetMass(50);
  SetArmourClass(ARMOUR_PLATE);
  SetValue(500);
  SetDamagePoints(400);
  SetProperty("multiples", 1);
  // SetProtection(BLUNT, 15);
  // SetProtection(PIERCE,25 );
  // SetProtection(SLASH, 20);
  SetArmourType(A_GLOVE);
  SetSize(SIZE_SMALL);
  SetMaterial( ({"mithril"}) );
  SetWarmth(3);
  SetRepairSkills( ([
    "mithril working" : 10,
     ]) );
  SetRepairDifficulty(60);
}
