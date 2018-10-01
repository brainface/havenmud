/*  Portia  10-14-98
     Pants for my elves.
*/

#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetShort("a pair of pants");
  SetId( ({"pants"}) );
  SetAdjectives( ({}) );
  SetLong("This pair of pants is made of cotton and looks quite durable.");
  SetValue(30);
  SetMass(30);
  SetMaterial( ({"textile"}) );
  SetWarmth(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetRepairSkills( ([
           "textile working" : 4,
            ]) );
  SetRepairDifficulty(20);
  SetDamagePoints(500);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  }
