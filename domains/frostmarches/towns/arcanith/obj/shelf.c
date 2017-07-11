#include <lib.h>
#include "../ruins.h"
inherit LIB_STORAGE;

static void create() {
   storage::create();
   SetShort("a wooden shelf");
   SetKeyName("wooden shelf");
   SetId( ({ "shelf" }) );
   SetAdjectives( ({ "wooden" }) );
   SetLong("This rough wooden shelf is sturdily attached "
     "between two wooden beams supporting the ceiling. It "
     "seems to a place where important items could be stored "
     "temporarily."
   );
   SetMass(200);
   SetCanClose(0);
   SetClosed(0);
   SetMaxCarry(90);
   SetPreventGet("This shelf is attached to a load bearing "
     "beam, removing it would be foolhardy.");
   SetPick(0);
   SetCanLock(0);
   SetLocked(0);
   SetOpacity(0);
   SetInventory( ([ OBJ "/marble_chunk" : random(3) + 1, ]) );

}

