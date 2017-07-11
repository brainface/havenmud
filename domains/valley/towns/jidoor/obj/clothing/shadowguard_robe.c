/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: shadowguard_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: May 11th, 1999
// Abstract: Shadowguard's Robe
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("shadowguard's robe");
  SetShort("a shadowguard's robe");
  SetAdjectives( ({ "black","silk" }) );
  SetId( ({ "robe" }) );
  SetProperty("history", "This is the standard issue robe for a Jidoor City "
             "Shadowguard.",);
  SetLong("This is a long black robe fashioned from silk on the outside and "
          "obviously padded on the inside.  On the left breast is the symbol "
          "of the city of Jidoor.");
  SetRepairSkills( ([ "textile working" : 15,]) );
  SetMaterial( ({ "textile" }) );
  SetSize(SIZE_MEDIUM);
  SetWarmth(4);
  SetArmourClass(ARMOUR_CLOTH);
  SetRepairDifficulty(15);
  SetMass(90);
  SetValue(800);
  SetDamagePoints(2000);
  // SetProtection(PIERCE, 8);
  // SetProtection(BLUNT, 8);
  // SetProtection(SLASH, 8);
  // SetProtection(COLD, 12);
}
