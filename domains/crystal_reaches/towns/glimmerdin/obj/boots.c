#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId( ({ "boots", }) );
  SetAdjectives( ({ "small", "leather" }) );
  SetShort("a pair of small leather boots");
  SetLong("The dark leather boots have a reinforced toe.");
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_LEATHER);
  SetMass(50);
  SetSize(SIZE_SMALL);
  SetValue(80);
  SetProperty("multiples", 1);
  SetDamagePoints(1400);
  // SetProtection(BLUNT, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(SLASH, 2);
  // SetProtection(COLD,2);
  SetArmourType(A_BOOT);
  SetMaterial( ({"leather"}) );
  SetRepairSkills( ([
                     "leather working" : 3,
                 ]) );
  SetRepairDifficulty(10);
}
