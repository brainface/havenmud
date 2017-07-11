#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("child");
  SetId( ({ "boy", "child"}) );
  SetAdjectives( ({"little"}) );
  SetShort("a little boy");
  SetLong(
    "The little boy has light brown hair and "
    "brown eyes. He is tall and wiry."
  );
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetLevel(4);
  
  SetMorality(900);
  SetAction(5, ({ 
    "The little boy shouts loudly.", 
    "The little boy runs around." 
  }));
  SetInventory( ([
    C_OBJ + "pants3" : "wear pants",
    C_OBJ + "shirt4" : "wear shirt" 
  ]) );
}
