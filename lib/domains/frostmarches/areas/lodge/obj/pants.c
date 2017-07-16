#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;
static void create() {
  armour::create();
  SetKeyName("pants");
  SetId( ({"pants"}) );
  SetShort("a pair of flesh made pants");
  SetLong("These pants are made of the pure flesh of a unidentifable being.  "
  "They are old and dusty but don't seem to be worn out yet.  For a quite disgusting "
  "attire, these pants look very comfortable.");
  SetAdjectives( ({"flesh"}) );
  SetMass(120);
  SetValue(75);
  SetMaterial( ({ "leather" }) );
  SetWarmth(15);
  SetRepairSkills( ([
  "amour smithing " : 4,
  ]) );
  SetRepairDifficulty(9);
  SetDamagePoints(410);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  // SetProtection(SLASH,10);
  // SetProtection(PIERCE,10);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:27:02 2000. */
