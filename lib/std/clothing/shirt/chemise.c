  /* chemise

  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("chemise");
  SetShort("a fine lawn chemise");
  SetId( ({"chemise"}) );
  SetAdjectives( ({"fine","lawn","white"}) );
  SetLong("This white chemise is made of the finest "
          "lawn available. It has a drawstring neck "
          "and waist.");
  SetMass(10);
  SetValue(25);
  SetDamagePoints(20);
  SetMaterial("textile");
  SetWarmth(8);
  SetArmourType(A_SHIRT);
}
