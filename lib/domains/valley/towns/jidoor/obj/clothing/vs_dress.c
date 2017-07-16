/* ----------------------------------------------------------------- */
// Area Title: Town of Jidoor
// Filename: sprite_dress.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: December 16th, 1998
// Abstract: This is the dress worn by female sprites.
// Revision History: 
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
  SetKeyName("dress");
  SetShort("a very small dress");
  SetAdjectives( ({ "very", "small" }) );
  SetId( ({ "dress" }) );
  SetLong("The dress is a cute little outfit for young girls to "
          "wear.  It doesn't appear to be outstanding craftsmanship "
          "and it seems to be rather plain.");
  SetMaterial( ({ "textile" }) );
  SetWarmth(13);
  SetArmourClass(ARMOUR_CLOTH);
  SetRepairSkills( ([ "textile working" : 1,]) );
  SetRepairDifficulty(5);
  SetValue(50);
  SetMass(15);
  SetDamagePoints(150);
  // SetProtection(COLD, 7);
  SetSize(SIZE_VERY_SMALL);
  }
