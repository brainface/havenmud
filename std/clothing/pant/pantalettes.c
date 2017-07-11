  /* pantalettes

  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("pantalettes");
  SetShort("a pair of pantalettes");
  SetId( ({"pantalettes"}) );
  SetAdjectives( ({"pair","lawn"}) );
  SetLong("This pair of pantalettes is made of the finest "
          "lawn available. It has a drawstring waist.");
  SetMass(10);
  SetValue(25);
  SetDamagePoints(20);
  SetMaterial("textile");
  SetWarmth(8);
  SetArmourType(A_PANTS);
}
