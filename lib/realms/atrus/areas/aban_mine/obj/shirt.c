/* shirt.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetShort("a leather shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"dark", "leather"}) );
  SetLong("This dark leather shirt is made of thick leather "
          "and covers the torso completely. The exterior is " 
          "covered with rock dust and has many scratches. "
          "It has been used hard, but it is well-maintained.");
  SetMass(60);
  SetValue(100);
  SetSize(SIZE_SMALL);
  SetDamagePoints(175);
  SetMaterial("leather");
  SetWarmth(8);
  SetArmourType(A_VEST);
  SetProtection(BLUNT, 2);
  SetProtection(ACID, 1);
  SetProtection(COLD, 1);
  SetProtection(HEAT, 1);
}
