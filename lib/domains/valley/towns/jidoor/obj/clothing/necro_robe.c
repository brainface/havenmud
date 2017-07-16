/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: necro_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: November 4th, 1998
// Abstract: Sprite Necromancer's Robe
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("black robe");
  SetShort("a black robe");
  SetAdjectives( ({ "black","silk" }) );
  SetId( ({ "robe" }) );
  SetProperty("history", "Wearing this robe in Jidoor would mark you as "
          "a necromancer.",);
  SetLong("This finely crafted silk robe is a jet black color "
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
