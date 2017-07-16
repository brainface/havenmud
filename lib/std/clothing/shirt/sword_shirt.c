  /* swordsman_shirt
  Luna 12/11/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("shirt");
  SetShort("a fitted purple shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"purple","fitted","narrow"}) );
  SetLong("This deep purple shirt has narrow fitted sleeves "
          "best suited for sword battle");
  SetMass(25);
  SetSize(SIZE_MEDIUM);
  SetValue(50);
  SetDamagePoints(50);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_SHIRT);
}
