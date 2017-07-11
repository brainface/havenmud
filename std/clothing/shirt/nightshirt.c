/* nightshirt
  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("nightshirt");
  SetShort("a nightshirt");
  SetId( ({"nightshirt"}) );
  SetAdjectives( ({"knee-length","cotton"}) );
  SetLong("This nightshirt is soft cotton. "
          "It is knee-length with long sleeves.");
  SetMass(20);
  SetValue(40);
  SetDamagePoints(30);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_SHIRT);
}
