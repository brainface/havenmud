//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Flag Pole
//

#include <lib.h>
#include "../dalnairn.h"

inherit LIB_STORAGEBOX;

mixed CanPutInto(object who, object item);

static void create() {
  ::create();
  SetKeyName("pole");
  SetId( ({"pole"}) );
  SetAdjectives( ({"flag", "tall", "mithril"}) );
  SetShort("a tall mithril flagpole");
  SetLong(
    "This is a tall flagpole made of mithril."
  );
  SetBoxID("daln_flag_pole");
  SetPreventGet("The flagpole refuses to budge.");
  SetMass(5000);
  SetMaterial("mithril");
  SetValue(0);
  SetCanClose(1);
  SetClosed(1);
  SetCanLock(1);
  SetLocked(1);
  SetLockStrength(25);
  SetMaxCarry(1);
  SetOpacity(0);
  SetInventory( ([
    DAL_OBJ "jolly_rose" : 1,
  ]) );
}

string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
}
