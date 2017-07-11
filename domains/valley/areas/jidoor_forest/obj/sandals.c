/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: sandals.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 23rd, 1998
// Abstract: This is a pair of sandals
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
//                   August 24th, 1998 - Fixed Morgoth Approval Suggestions
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;


static void create() 
  {
  armour::create();
  SetKeyName("a pair of leather sandals");
  SetId( ({ "sandals" }) );
  SetAdjectives( ({ "pair of","leather" }) );
  SetSize(SIZE_VERY_SMALL);
  SetShort("a pair of leather sandals");
  SetLong("Fashioned from leather, these sandals look very "
          "comfortable. They do not appear expensive nor do they "
          "appear to offer any protection to one's feet.");
  SetVendorType(VT_ARMOUR);
  SetMass(40);
  SetValue(180);
  SetProperty("multiples", 1);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(200);
  SetArmourType(A_BOOT);
  SetMaterial( ({"leather"}) );
  SetWarmth(2);
  SetRepairSkills( (["leather working" : 3,]) );
  SetRepairDifficulty(11);
  }
