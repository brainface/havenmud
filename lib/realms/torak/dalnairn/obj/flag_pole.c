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
  SetId( ({"pole", "flagpole"}) );
  SetAdjectives( ({"flag", "tall", "mithril"}) );
  SetShort("a tall mithril flag pole");
  SetLong(
    "This is a tall flag pole made of mithril."
  );
  SetBoxID("daln_flag_pole");
  SetPreventGet("The flag pole refuses to budge.");
  SetMass(5000);
  SetMaterial("mithril");
  SetValue(0);
  SetCanClose(1);
  SetClosed(1);
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
