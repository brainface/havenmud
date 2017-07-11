/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: diviner_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: November 4th, 1998
// Abstract: Sprite Diviner's Robe
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("dark green robe");
  SetShort("a dark green robe");
  SetAdjectives( ({ "green","silk","dark" }) );
  SetId( ({ "robe" }) );
  SetProperty("history", "Wearing this robe in Jidoor would mark you as "
          "a diviner.",);
  SetLong("This finely crafted silk robe is an emerald greenish color "
          "and looks like the perfect size for a lamrani. It has a few "
          "embroidered stitches near the hood and the cuffs.");
  SetRepairSkills( ([ "textile working" : 10,]) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(25);
  SetArmourClass(ARMOUR_CLOTH);
  SetRepairDifficulty(10);
  SetMass(70);
  SetValue(600);
  SetDamagePoints(1000);
  // SetProtection(PIERCE, 5);
  // SetProtection(BLUNT, 5);
  // SetProtection(SLASH, 5);
  // SetProtection(COLD, 5);
  }
