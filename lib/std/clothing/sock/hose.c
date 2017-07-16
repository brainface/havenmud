  /* hose shoes
  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("hose");
  SetShort("a pair of hose");
  SetId( ({"hose"}) );
  SetAdjectives( ({"pair","black","wool"}) );
  SetLong("This pair of hose is made of light black "
          "wool.");
  SetMass(10);
  SetValue(25);
  SetDamagePoints(20);
  SetMaterial("textile");
  SetWarmth(7);
  SetArmourType(A_LONG_SOCK);
}
