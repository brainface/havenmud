   /*muslin_shirt
  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("shirt");
  SetShort("a muslin shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"muslin","natural"}) );
  SetLong("This muslin shirt is natural with long, full "
          "sleeves. It has a v-neck with a tie closure. ");
  SetMass(30);
  SetValue(50);
  SetDamagePoints(25);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_SHIRT);
}
