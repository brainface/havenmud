#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;
static void create() {
  armour::create();
  SetKeyName("vest");
  SetId( ({"vest"}) );
  SetShort("a vest of dismemberment");
  SetLong("This vest is made of the flesh of some kind of being.  The skin "
  "is rough and thick.  It looks great for insulation and covers the majority "
  "of the torso area.");
  SetAdjectives( ({"dismembered"}) );
  SetMass(110);
  SetValue(175);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"leather"}) );
  SetWarmth(10);
  SetRepairSkills( ([
     "armour smithing" : 4,
  ]) );
  SetRepairDifficulty(9);
  SetDamagePoints(410);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  // SetProtection(SLASH,10);
  // SetProtection(PIERCE,10);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:30:14 2000. */
