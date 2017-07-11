#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;


static void create() {
  armour::create();
  SetKeyName("mithril shield");
  SetId( ({ "shield" }) );
  SetAdjectives( ({ "dwarven", "mithril", }) );
  SetShort("a dwarven mithril shield");
  SetLong(
    "This shield is made of thick, shimmering mithril. Its ability "
    "to prevent damage is significant."
    );
  SetDamagePoints(3000);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMass(400);
  SetValue(750);
  SetArmourType(A_SHIELD);
  // SetProtection(BLUNT, 35);
  // SetProtection(SLASH, 50);
  // SetProtection(PIERCE, 50);
  // SetProtection(SHOCK, 20);
  SetMaterial( ({ "mithril" }) );
  SetRepairDifficulty(60);
  SetRepairSkills( ([
     "armour smithing" : 4,
     "mithril working" : 4,
     ]) );
}
 
