 /* surcoat
  Luna 12/13/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("surcoat");
  SetShort("a surcoat");
  SetId( ({"surcoat"}) );
  SetAdjectives( ({"gray","canvas"}) );
  SetLong("This steel gray canvas surcoat is made to be worn over "
          "armour. It is cut generously for comfort");
  SetMass(40);
  SetValue(80);
  SetDamagePoints(80);
  SetMaterial("textile");
  SetWarmth(20);
  SetArmourType(A_CLOAK);
}
