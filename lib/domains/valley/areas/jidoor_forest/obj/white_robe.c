/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: white_robe.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 21th, 1998
// Abstract: This is the magical robe worn a wandering Magildan Priest
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create()
  {
  ::create();
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_VERY_SMALL);
  SetKeyName("white robe");
  SetShort("a white robe");
  SetAdjectives( ({ "white"}) );
  SetId( ({ "robe" }) );
  SetLong("This garment was once worn by a priest of the Magildan "
          "faith but is no longer.  It is made of a fine cloth, and "
          "appears comfortable, but slightly bulky.");
  SetRepairSkills( ([ "textile working" : 1,]) );
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetWarmth(20);
  SetRepairDifficulty(40);
  SetMass(120);
  SetValue(200);
  SetDamagePoints(500);
  // SetProtection(HEAT, 10);
  // SetProtection(SHOCK, 10);
  // SetProtection(COLD, 10);
  // SetProtection(SLASH, 3);
  }
