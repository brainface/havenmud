/*blue dress
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
  SetShort("a blue dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"blue","simple","cotton"}) );
  SetLong("This blue cotton dress is simple in design and suited "
          "for every-day use. It has short cap sleeves. "
        "The neckline is softly rounded.");
  SetMass(30);
  SetValue(50);
  SetWarmth(10);
  SetDamagePoints(30);
  SetMaterial("textile");
  SetArmourType(A_BODY_ARMOUR);
}
