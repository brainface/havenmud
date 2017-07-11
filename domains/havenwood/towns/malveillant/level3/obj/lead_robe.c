/*   Portia  12-16-98
      The robe for the leaders.
 */

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include "../mal.h"
inherit LIB_ARMOUR;

 static void create() {
 armour::create();
 SetShort("an extravagent black robe");
 SetKeyName("robe");
 SetId( ({"robe"}) );
 SetAdjectives( ({ "extravagent", "black"}) );
 SetVendorType(VT_CLOTHING);
 SetArmourType(A_BODY_ARMOUR);
 SetDamagePoints(1000);
 SetValue(800);
 SetRepairSkills( ([
   "textile working" : 1,
   ]) );
 SetRepairDifficulty(5);
 SetLong("This long black robe is highly decorated and "
   "seems to be worn only by people of high stature.");
 SetMaterials( ({"textile"}) );
  SetWarmth(20);
 SetMass(60);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_CLOTH);
 }
