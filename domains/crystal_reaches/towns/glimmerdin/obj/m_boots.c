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
  SetAdjectives( ({ "leather", }) );
  SetShort("a pair of leather boots");
  SetLong("The dark leather boots have a reinforced toe.");
  SetVendorType(VT_ARMOUR);
  SetMass(50);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_SMALL);
  SetValue(80);
  SetDamagePoints(4500);
  // SetProtection(BLUNT, 5);
     SetProperty("multiples", 1);
  // SetProtection(PIERCE,10);
  // SetProtection(SLASH, 10);
  // SetProtection(COLD,2);
  SetArmourType(A_BOOT);
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetRepairSkills( ([
    "leather working" : 3,
    ]) );
  SetRepairDifficulty(10);
}
