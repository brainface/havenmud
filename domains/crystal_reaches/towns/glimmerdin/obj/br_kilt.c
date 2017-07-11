#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("blood rock kilt");
  SetId( ({ "kilt"}) );
  SetAdjectives( ({ "blood", "rock","clan", "red", "grey", "plaid" }) );
  SetShort("a red and grey plaid kilt");
  SetLong(
    "The red and grey plaid pattern is of the Blood Rock Clan."
    );
  SetVendorType(VT_CLOTHING);
  SetMass(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetValue(15);
  SetDamagePoints(180);
  // SetProtection(HEAT, 2);
  // SetProtection(COLD, 4);
  // SetProtection(BLUNT, 3);
  // SetProtection(PIERCE, 3);
  // SetProtection(SLASH, 3);
  SetArmourType(A_PANTS);
  SetMaterial( ({"textile"}) );
  SetWarmth(8);
  SetRepairSkills( ([
                     "textile working" : 3,
                 ]) );
  SetRepairDifficulty(10);
}
