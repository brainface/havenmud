//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Restaurant Table
//

#include <lib.h>
#include "../dalnairn.h"
#include "/domains/valley/areas/bazaar/bazaar.h"

inherit LIB_STORAGE;

mixed CanPutInto(object who, object item);

static void create() {
  ::create();
  SetKeyName("table");
  SetId( ({
    "table"
  }) );
  SetAdjectives( ({ 
    "round", "wooden", "wood"
  }) );
  SetShort("a round wooden table");
  SetLong(
    "This is a round wooden table."
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
    BAZAAR_OBJ "tulip" : 1,
    DAL_OBJ "candle" : 1,
    DAL_OBJ "tablecloth" : 1,
  ]) );
}
 
string GetExternalDesc() {
  string desc;
  desc = ::GetExternalDesc();
  desc += ::GetInternalDesc();
  return desc;
}
