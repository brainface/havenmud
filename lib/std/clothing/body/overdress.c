 /* overdress
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("dress");
  SetShort("a brocade overdress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"green","ankle-length"}) );
  SetLong("This floral brocade overdress is sleeveless "
          "and is meant to be worn over a dress.");
  SetMass(50);
  SetValue(50);
  SetDamagePoints(50);
  SetMaterial("textile");
  SetWarmth(15);
  SetArmourType(A_BODY_ARMOUR);
}
