/* ----------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: dress.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 21th, 1998
// Abstract: This is the dress worn by Lauranna.
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
  SetSize(SIZE_VERY_SMALL);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("green dress");
  SetShort("a green dress");
  SetAdjectives( ({ "green" }) );
  SetId( ({ "dress" }) );
  SetLong("A perfect outfit for a woman who wishes to bask in the "
          "sunlight and reveal some of herself, but keep the majority "
          "of her womanly charms under wraps.  It is a carefree "
          "and classy looking outfit.");
  SetMaterial( ({ "textile" }) );
  SetWarmth(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetRepairSkills( ([ "textile working" : 1,]) );
  SetRepairDifficulty(5);
  SetValue(300);
  SetMass(15);
  SetDamagePoints(150);
  // SetProtection(COLD, 10);
  }
