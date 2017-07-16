/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("rimrock kilt");
  SetId( ({ "kilt"}) );
  SetAdjectives( ({ "rimrock","clan","green, grey and blue","plaid" }) );
  SetShort("a green, grey and blue plaid kilt");
  SetLong("The green, grey and blue plaid pattern is of the Rimrock Clan.");
  SetVendorType(VT_CLOTHING);
  SetMass(15);
  SetValue(15);
  SetDamagePoints(180);
  SetArmourClass(ARMOUR_CLOTH);
  // SetProtection(HEAT, 2);
  // SetProtection(COLD, 4);
  // SetProtection(BLUNT, 3);
  // SetProtection(PIERCE, 3);
  // SetProtection(SLASH, 3);
  SetArmourType(A_PANTS);
  SetMaterial( ({"textile"}) );
  SetWarmth(10);
  SetSize(SIZE_SMALL);
  SetRepairSkills( ([
     "textile working" : 3,
     ]) );
  SetRepairDifficulty(10);
}
