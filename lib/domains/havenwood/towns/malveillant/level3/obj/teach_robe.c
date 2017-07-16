/*   Portia  12-16-98
      The robe for the teachers.
 */

#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include "../mal.h"
inherit LIB_ARMOUR;

 static void create() {
 armour::create();
 SetShort("a soft linen robe");
 SetKeyName("robe");
 SetId( ({"robe"}) );
 SetAdjectives( ({ "soft", "linen"}) );
 SetVendorType(VT_CLOTHING);
 SetArmourType(A_BODY_ARMOUR);
 SetDamagePoints(300);
 SetValue(40);
 SetRepairSkills( ([
   "textile working" : 1,
   ]) );
 SetRepairDifficulty(5);
 SetLong("This robe looks very soft. It is a dull grey color "
   "and appears to have been worn excessively throughout the "
   "years.");
 SetMaterials( ({"textile"}) );
 SetWarmth(15);
 SetArmourClass(ARMOUR_CLOTH);
 SetSize(SIZE_MEDIUM);
 SetMass(40);
 }
