#include <lib.h>
#include <jump.h>
#include "../dalnairn.h"

inherit LIB_ITEM;
inherit LIB_JUMP;
 
 
static void create() {
   item::create();
   SetShort("a windowframe");
   SetLong(
    "This is an open wooden windowframe. "
    "It is made to fit a panel of glass "
    "but for unkown reason there is no panel here now. "
   );
   SetId( ({"window", "windowframe"}) );
  SetJump(
    DAL_ROOM "2,1", JUMP_THROUGH
  );
  SetMaterials( ({"wood"}) );
  SetAdjectives( ({ 
    "open","wood", "wooden" 
  }) );
  SetInvis(2);
  SetKeyName("window");
  SetPreventGet("Somehow that doesn't seem to work.");
}
