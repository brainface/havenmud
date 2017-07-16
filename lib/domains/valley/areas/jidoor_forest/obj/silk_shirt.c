/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: silk_shirt.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 21th, 1998
// Abstract: This is a silk shirt
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
  SetShort("a silk shirt");
  SetLong("This white silk shirt looks expensive and comfortable. "
          "It looks like it would keep you warm it doesn't look like "
          "much in the way of armour.");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "white","silk","expensive","comfortable" }) );
  SetValue(400);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetKeyName("silk shirt");
  SetDamagePoints(200);
  SetRepairSkills( ([
    "textile working" : 8,
    ]) );
  SetRepairDifficulty(8);
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetMass(25);
  }
