 /* fencing_vest
  Luna 12/13/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("vest");
  SetShort("a fencing vest");
  SetId( ({"vest"}) );
  SetAdjectives( ({"gray","canvas"}) );
  SetLong("This heavy black canvas vest is made to protect it's "
          "wearer from the sharp tip of a rapier. It has wide "
          "shoulders and is double-breasted.");
  SetMass(30);
  SetValue(60);
  SetDamagePoints(60);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_VEST);
}
