/* ----------------------------------------------------------------------- */
// Area Title: standard clothing
// Filename: black_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: December 17th, 1998
// Abstract: just a standard black robe of not too much extravagence.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("black cultist robe");
  SetId( ({ "robe" }) );
  SetShort("a black cultist's robe");
  SetAdjectives( ({ "black", "cultist", "cultist's" }) );
  SetLong("The black robe is a well-reinforced article of clothing. "
          "The robe is rather "
          "bulky and heavy as well. A small amount of embroidery is "
          "visible around the trim of the collar, the cuffs and the "
          "brocade. It is a long flowing garment and would likely offer a "
          "slight amount of protection against the cold.");
  SetWarmth(30);
  SetRepairSkills( ([ "textile working" : 1,]) );
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(30);
  SetMass(80);
  SetValue(75);
  SetDamagePoints(4000);
  SetProtectionBonus(BLUNT, 20);
  SetProtectionBonus(SLASH, 20);
  SetProtectionBonus(PIERCE, 20);
  SetProtectionBonus(HEAT, 20);
  SetProtectionBonus(COLD, 20);
  SetProtectionBonus(SHOCK, 20);
  SetProtectionBonus(MAGIC, 20);
}
