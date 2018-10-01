/* A cloak which marks the person as a 
 * certified NEWBIE HELPER, Woo!
 */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("cloak");
  SetArmourType(A_CLOAK);
  SetShort("an ugly brown cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "ugly", "brown" }) );
  SetLong("This is an ugly brown cloak.");
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(250);
  SetValue(50);
}
