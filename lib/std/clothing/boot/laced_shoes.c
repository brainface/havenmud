  /* laced shoes shoes
  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
   SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) );
  SetKeyName("shoes");
  SetShort("a pair of laced shoes");
  SetId( ({"shoes"}) );
  SetAdjectives( ({"brocade","natural"}) );
  SetLong("These shoes are made of soft black leather. "
          "They lace in the front.");
  SetMass(30);
  SetValue(50);
  SetDamagePoints(40);
  SetMaterial("leather");
  SetWarmth(5);
  SetProperty("multiples", 1);
  SetArmourType(A_BOOT);
}
