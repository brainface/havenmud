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
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("dark green robe");
  SetShort("a very small dark green robe");
  SetAdjectives( ({ "very", "small", "dark", "green", "silk" }) );
  SetId( ({ "robe" }) );
  SetProperty("history", "Wearing this robe in Jidoor would mark you as "
          "a diviner.",);
  SetLong("This finely crafted silk robe is an emerald greenish color "
          "and looks like the perfect size for a sprite.  It has a few "
          "embroidered stitches near the hood and the cuffs.");
  SetRepairSkills( ([ "textile working" : 10,]) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(25);
  SetRepairDifficulty(10);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(70);
  SetValue(600);
  SetSize(SIZE_VERY_SMALL);
  SetDamagePoints(1000);
  // SetProtection(PIERCE, 5);
  // SetProtection(BLUNT, 5);
  // SetProtection(SLASH, 5);
  // SetProtection(COLD, 5);
  }
