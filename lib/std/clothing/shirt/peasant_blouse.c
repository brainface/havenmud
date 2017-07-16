  /*peasant_blouse
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("blouse");
  SetShort("a peasant blouse");
  SetId( ({"blouse"}) );
  SetAdjectives( ({"cotton","white"}) );
  SetLong("This cotton blouse is white with a gathered "
          "neck and sleeves. It can be worn on or off "
          "the shoulders.");
  SetMass(30);
  SetValue(50);
  SetDamagePoints(25);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_SHIRT);
}
