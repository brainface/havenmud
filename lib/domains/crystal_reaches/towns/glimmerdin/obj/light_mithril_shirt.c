#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("light mithril shirt");
  SetId( ({ "shirt", }) );
  SetAdjectives( ({ "light", "mithril" }) );
  SetShort("a light mithril shirt");
  SetLong("The finest mithril makes up this lightweight shirt.");
  SetVendorType(VT_ARMOUR);
  SetMass(15);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_CHAIN);
  SetValue(1000);
  SetDamagePoints(5700);
  // SetProtection(HEAT, 2);
  // SetProtection(COLD, 4);
  // SetProtection(BLUNT, 6);
  // SetProtection(PIERCE, 12);
  // SetProtection(SLASH, 16);
  SetArmourType(A_SHIRT);
  SetMaterial( ({"mithril"}) );
  SetWarmth(5);
  SetRepairSkills( ([
     "mithril working" : 9,
     ]) );
  SetRepairDifficulty(50);
}
