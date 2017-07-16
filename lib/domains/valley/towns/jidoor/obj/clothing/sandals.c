/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: sandals.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Novemnber 4th, 1998
// Abstract: This is a pair of sandals for sprites
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("a pair of leather sandals");
  SetId( ({ "sandals" }) );
  SetAdjectives( ({ "pair of","leather" }) );
  SetShort("a pair of leather sandals");
  SetLong("Fashioned from leather, these sandals look "
          "comfortable. They do not appear expensive nor do they "
          "appear to offer any protection to one's feet.");
  SetVendorType(VT_ARMOUR);
  SetMass(15);
  SetValue(180);
   SetProperty("multiples", 1);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(750);
  SetArmourType(A_BOOT);
  SetMaterial( ({"leather"}) );
  SetWarmth(2);
  SetRepairSkills( (["leather working" : 1,]) );
  SetRepairDifficulty(4);
  }
