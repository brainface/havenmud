/*   Portia  12-16-98
      The robe for the students.
 */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <size.h>
#include "../mal.h"
inherit LIB_ARMOUR;

 static void create() {
 armour::create();
 SetShort("a crisp white robe");
 SetKeyName("robe");
 SetId( ({"robe"}) );
 SetAdjectives( ({ "crisp", "white"}) );
 SetVendorType(VT_CLOTHING);
 SetArmourType(A_BODY_ARMOUR);
 SetDamagePoints(200);
 SetValue(20);
 SetRepairSkills( ([
   "textile working" : 1,
   ]) );
 SetRepairDifficulty(5);
 SetLong("This crisp robe looks relatively new and very clean. "
   "It doesn't appear to be very durable.");
 SetMaterials( ({"textile"}) );
 SetWarmth(10);
 SetMass(40);
  SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
 }
