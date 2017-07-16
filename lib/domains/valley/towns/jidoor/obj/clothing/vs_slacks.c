/* ----------------------------------------------------------------- */
// Area Title: Town of Jidoor
// Filename: slacks.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 21th, 1998
// Abstract: This is a pair of tiny slacks for sprite children
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <lib.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create()
  {
  ::create();
  SetId( ({ "slacks" }) );
  SetShort("a pair of very small slacks");
  SetLong("These slacks look comfortable but not too expensive.  They also look "
          "like they could keep you warm but don't seem to "
          "be much in the way of armour.");
  SetAdjectives( ({ "comfortable","" }) );
  SetValue(200);
  SetMass(30);
  SetArmourType(A_PANTS);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetKeyName("very small slacks");
  SetDamagePoints(175);
  SetRepairSkills( ([ "textile working" : 2, ]) );
  SetRepairDifficulty(8);
  SetMaterial( ({ "textile" }) );
  SetWarmth(15);
  SetSize(SIZE_VERY_SMALL);
  }
