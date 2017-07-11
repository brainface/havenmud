/* ----------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: silk_slacks.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 21th, 1998
// Abstract: This is a pair of silk slacks.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <lib.h>
inherit LIB_ARMOUR;

static void create()
  {
  ::create();
  SetId( ({ "slacks" }) );
  SetShort("a pair of silk slacks");
  SetLong("This pair of green slacks looks expensive and comfortable. "
          "They look like they could keep you warm but don't seem to "
          "be much in the way of armour.");
  SetAdjectives( ({ "expensive", "green", "comfortable","silk" }) );
  SetValue(400);
  SetMass(35);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetKeyName("green silk slacks");
  SetDamagePoints(275);
  SetRepairSkills( ([ "textile working" : 8, ]) );
  SetRepairDifficulty(8);
  SetMaterial( ({ "textile" }) );
  SetWarmth(20);
  }
