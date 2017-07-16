#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include "../lodge.h"


inherit LIB_STORAGE;

static void create() {
 object cash = new(LIB_PILE);  

  storage::create();
  cash->SetPile("imperials", 9000);
  cash->eventMove(this_object());
  SetKeyName("chest");
  SetId( ({"chest"}) );
  SetShort("a large chest");
  SetLong("This chest is big and hollow, probably one of the "
     "only things neatly kept. It looks like it could hold "
     "a small treasure.");
  SetAdjectives( ({"large"}) );
  SetPreventGet("The chest is nailed to the floor, preventing you from getting it.");
  SetMass(100000);
  SetMaxCarry(10000000000000);
  SetValue(0);
  SetCanClose(1);
  SetClosed(1);
  SetCanLock(1);
  SetLocked(1);
  SetMaterial( ({"wood"}) );
  SetDamagePoints(1000);
  SetLockStrength(500);
  SetKeys( ({ "ice_key" }) );
}

mixed eventUnlock(object who, object key) {
  mixed res = ::eventUnlock(who, key);
  if (res == 1) { key->eventDestruct(); }
  who->eventPrint("Your key melts as it unlocks the chest.");
  return res;
}
