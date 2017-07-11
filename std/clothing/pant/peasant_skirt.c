  /* peasant_skirt
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("skirt");
  SetShort("a peasant skirt");
  SetId( ({"skirt"}) );
  SetAdjectives( ({"cotton","heavy","ankle-length","brown"}) );
  SetLong("This brown ankle-length skirt is made of "
          "heavy cotton.");
  SetMass(40);
  SetValue(50);
  SetDamagePoints(30);
  SetMaterial("textile");
  SetWarmth(15);
  SetArmourType(A_PANTS);
}
