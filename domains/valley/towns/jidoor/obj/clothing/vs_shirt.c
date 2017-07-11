/* ----------------------------------------------------------------------- */
// Area Title: Town of Jidoor
// Filename: shirt.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: December 16h, 1998
// Abstract: This is a child's shirt
/* ----------------------------------------------------------------------- */

#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create()
  {
  ::create();
  SetShort("a very small white shirt");
  SetLong("This white shirt looks to be comfortable but it wouldn't "
          "provide much protection against anything but the cold.");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "white","comfortable" }) );
  SetValue(100);
  SetArmourType(A_SHIRT);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetKeyName("silk shirt");
  SetDamagePoints(200);
  SetRepairSkills( ([
    "textile working" : 1,
    ]) );
  SetRepairDifficulty(5);
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetMass(25);
  SetSize(SIZE_VERY_SMALL);
  }
