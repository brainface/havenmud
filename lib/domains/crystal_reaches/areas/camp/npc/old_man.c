#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("man");
  SetId( ({ "man"}) );
  SetAdjectives(  ({"old"})  );
  SetShort("an old man");
  SetLong(
    "The old man's face is weathered and worn. "
    "His thick white hair looks disheveled. A look of "
    "pure sorrow fills his warm brown eyes."
  );
  SetRace("human");
  SetClass("rogue");
  SetLevel(5);
  
  SetGender("male");
  SetMorality(100);
  SetAction(5, ({ 
    "The old man looks down sadly." 
  }));
  SetInventory( ([
    C_OBJ + "pants1" : "wear pants",
    C_OBJ + "shirt1" : "wear shirt" 
  ]) );
}
