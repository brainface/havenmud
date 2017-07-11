  /* leather_jerkin
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("jerkin");
  SetShort("a leather jerkin");
  SetId( ({"jerkin"}) );
  SetAdjectives( ({"brown","leather","hard-wearing"}) );
  SetLong("This dark brown leather jerkin is preferred "
          "by soldiers and mercenaries for it's hard-wearing "
          "quality. It has wooden buttons with leather thong "
          "loops.");
  SetMass(60);
  SetValue(75);
  SetDamagePoints(75);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_VEST);
}
