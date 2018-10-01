//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Oyster Shell
//

#include <lib.h>
#include "../dalnairn.h"

inherit LIB_STORAGE;

static void create() {
  ::create();
  SetKeyName("shell");
  SetId( ({
    "shell", "oyster"
  }) );
  SetAdjectives( ({
    "oyster", "rock", "dalnairi"
  }) );
  SetShort("a dalnairi rock oyster");
  SetLong(
    "The rough shell of this rock osyter is hard and grey with an uneven surface."
  );
  SetMass(5);
  SetMaterial("natural");
  SetValue(0);
  SetCanClose(1);
  SetClosed(1);
  SetCanLock(1);
  SetLocked(0);
  SetDamagePoints(100);
  SetLockStrength(0);  
  SetMaxCarry(12);
  SetInventory( ([
    DAL_OBJ "r_pearl" : 1,
  ]) );
}
