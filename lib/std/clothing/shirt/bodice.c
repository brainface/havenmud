  /* bodice
  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("bodice");
  SetShort("a brocade bodice");
  SetId( ({"bodice"}) );
  SetAdjectives( ({"brocade","natural"}) );
  SetLong("This brocade bodice is low cut in front "
          "and laces up the back. It is meant to be "
          "worn over a chemise or dress.");
  SetMass(20);
  SetValue(50);
  SetDamagePoints(25);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_SHIRT);
}
