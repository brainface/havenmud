#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("assistant");
  SetId( ({"assistant"}) );
  SetAdjectives( ({"fortuneteller's"}) );
  SetShort("the fortuneteller's assistant");
  SetLong(
    "The assistant is little girl with black hair and "
    "brown eyes. Her face has a seriousness to it "
    "that's unusual for one so young."
  );
  SetRace("human");
  SetGender("female");
  SetClass("rogue");
  SetLevel(3);
  
  SetMorality(900);
  SetAction(5, ({ "The assistant waits patiently for a task. "}));
  SetInventory( ([C_OBJ + "dress2" : "wear dress" ]) );
}
