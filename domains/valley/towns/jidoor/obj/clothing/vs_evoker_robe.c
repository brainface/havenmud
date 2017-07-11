/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: evoker_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: November 4th, 1998
// Abstract: Sprite Evoker's Robe
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
  SetKeyName("dark blue robe");
  SetShort("a very small dark blue robe");
  SetAdjectives( ({ "very", "small", "dark", "blue", "silk" }) );
  SetId( ({ "robe" }) );
  SetProperty("history", "Wearing this robe in Jidoor would mark you as "
          "a evoker.",);
  SetLong("This finely crafted silk robe is dark blue color "
          "and looks like the perfect size for a sprite. It has a few "
          "embroidered stitches near the hood and the cuffs.");
  SetRepairSkills( ([ "textile working" : 10,]) );
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_VERY_SMALL);
  SetWarmth(25);
  SetRepairDifficulty(10);
  SetMass(70);
  SetValue(600);
  SetDamagePoints(1000);
  // SetProtection(PIERCE, 5);
  // SetProtection(BLUNT, 5);
  // SetProtection(SLASH, 5);
  // SetProtection(COLD, 5);
}
