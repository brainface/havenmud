/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: fishing_hat.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is a just a fishing hat.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create()
  {
  armour::create();
  SetKeyName("hat");
  SetShort("a fishing hat");
  SetId( ({ "hat" }) );
  SetAdjectives( ({ "floppy" }) );
  SetLong("This floppy fishing hat is covered with lures and hooks. "
          "It wouldn't offer any protection other than blocking the "
          "sun from your eyes.");
  SetMass(5);
  SetValue(100);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_HELMET);
  SetMaterial( ({ "textile" }) );
  SetWarmth(4);
  SetDamagePoints(100);
  SetRepairDifficulty(1);
  SetRepairSkills( (["textile working" : 0,]) );
  }
