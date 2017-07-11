#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("child");
  SetId( ({"girl", "child"}) );
  SetAdjectives( ({"little"}) );
  SetShort("a little girl");
  SetLong(
    "The little girl has black hair and dark "
    "brown eyes. Her skin is darkly tanned from "
    "playing outside."
  );
  SetRace("human");
  SetGender("female");
  SetClass("rogue");
  SetLevel(3);
  
  SetMorality(900);
  SetAction(5, ({ 
    "The little girl skips lightly.",
    "The little girl hums softly." 
  }));
  SetInventory( ([
    C_OBJ + "dress2" : "wear dress" 
  ]) );
}
