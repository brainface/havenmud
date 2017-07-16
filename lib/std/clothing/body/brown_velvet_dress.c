 /* brown velvet dress
  Luna 12/15/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("dress");
  SetShort("a brown velvet dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"brown","close-fitting","velvet","belted"}) );
  SetLong("This rich brown velvet dress is close-fitting "
          "with a gently flaring hem. It is belted with "
          "a gold link belt.");
  SetMass(40);
  SetValue(75);
  SetDamagePoints(30);
  SetMaterial("textile");
  SetWarmth(15);
  SetArmourType(A_BODY_ARMOUR);
}
