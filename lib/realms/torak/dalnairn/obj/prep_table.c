//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Prep Table
//

#include <lib.h>
#include "../dalnairn.h"

inherit LIB_STORAGE;

mixed CanPutInto(object who, object item);

static void create() {
  ::create();
  SetKeyName("table");
  SetId( ({
    "table", "station"
  }) );
  SetAdjectives( ({ 
    "long", "wooden", "wood", "prep", "preparation",
  }) );
  SetShort("a wooden table");
  SetLong(
    "This is a long wooden table. "
    "A cutting board has been placed upon it "
    "and it is being used to prepare food. "
  );
  SetPreventGet("The table refuses to budge.");
  SetMass(500);
  SetMaterial("wood");
  SetValue(0);
  SetCanClose(0);
  SetClosed(0);
  SetCanLock(0);
  SetLocked(0);
  SetMaxCarry(5000);
  SetOpacity(0); 
  SetInventory( ([
    DAL_OBJ "r_ingredient" : 1 + random(3),
    DAL_WPN "kitchen_knife" : 1,
// cutting board
  ]) );
}
 
string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
}
