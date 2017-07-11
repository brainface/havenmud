// Aless
// Added to camp in response to Bjorn Bug

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include "../camp.h"

inherit LIB_STORAGE;

static void create() {
  storage::create();

  SetKeyName("chest");
  SetId( ({"chest"}) );
  SetShort("a large cedar chest");
  SetLong("This large cedar chest is covered in painted stars "
     "and looks like it is firmly affixed to the floor of the "
     "wagon. No doubt the gypsies are slightly more cautious "
     "about security than their unwitting victims. ");
  SetAdjectives( ({"large", "cedar"}) );
  SetPreventGet("The chest is nailed to the floor. Did you "
     "really think you could walk away with it? ");
  SetMass(100000);
  SetMaxCarry(10000000000);
  SetValue(0);
  SetCanClose(1);
  SetClosed(1);
  SetCanLock(1);
  SetLocked(1);
  SetLockStrength(500);
  SetMaterial( ({"wood"}) );
  SetDamagePoints(100000);
}
