 /* fencing_breeches
  Luna 12/13/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("breeches");
  SetShort("a pair of fencing breeches");
  SetId( ({"breeches"}) );
  SetAdjectives( ({"close-fitting","cuffed","canvas"}) );
  SetLong("These canvas breeches are close_fitting and are "
          "cuffed below the knee.");
  SetMass(30);
  SetValue(60);
  SetDamagePoints(60);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_PANTS);
}
