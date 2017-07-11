  /* warrior_shirt
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("shirt");
  SetShort("a warrior shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"red","soft","cotton"}) );
  SetLong("This soft cotton shirt is made to be worn under armour. "
          "It's color is red so that enemies cannot see "
          "the wearer bleed.");
  SetMass(25);
  SetValue(40);
  SetDamagePoints(25);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_SHIRT);
}
