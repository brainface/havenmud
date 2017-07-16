#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) 
); 
  SetKeyName("dress");
  SetShort("a black and white maid dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"black","white", "simple", }) );
  SetLong("This black and white dress is standard for maids. "
          "Its a very simple design however it seems to have a "
          "stunning glow around it.");
  SetMass(25);
  SetValue(500);
  SetWarmth(20);
  SetDamagePoints(3000);
  SetMaterial("textile");
  SetArmourType(A_BODY_ARMOUR);
}
