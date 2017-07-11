  /* thigh hight boots shoes
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
  SetKeyName("boots");
  SetShort("a pair of thigh high boots");
  SetId( ({"boots"}) );
  SetAdjectives( ({ "thigh", "high" }) );
  SetLong("These boots are made of soft black leather. "
          "They reach the thigh.");
  SetMass(50);
  SetValue(75);
  SetProperty("multiples", 1);
  SetDamagePoints(50);
  SetMaterial("leather");
  SetWarmth(7);
  SetArmourType(A_BOOT);
  SetProperty("multiples", 1);
}
