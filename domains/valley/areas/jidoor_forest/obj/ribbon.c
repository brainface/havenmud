/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: ribbon.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 23rd, 1998
// Abstract: This is a ribbon made of lace used to tie one's hair.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create()
  {
  armour::create();
  SetSize(SIZE_VERY_SMALL);
  SetKeyName("a green lace ribbon");
  SetShort("a green lace ribbon");
  SetId( ({ "ribbon" }) );
  SetAdjectives ( ({ "green", "lace" }) );
  SetLong("Using this lace ribbon, one could fix up their "
          "hair to look more fashionable.");
  SetMass(1);
  SetValue(100);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_HELMET);
  SetMaterial( ({ "textile" }) );
  SetWarmth(0);
  SetDamagePoints(100);
  SetRepairDifficulty(1);
  SetRepairSkills( (["textile working" : 0,]) );
  }
