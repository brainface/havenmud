#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("man");
  SetId( ({ "man"}) );
  SetAdjectives( ({"short"}) );
  SetShort("a short man");
  SetLong(
    "This man is about the height of a petite "
    "female. He has dark skin, black hair, and black "
    "eyes. His face doesn't reveal a single emotion. "
  );
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetLevel(20);

  SetMorality(-100);
  SetAction(5, ({ 
    "!emote looks about nonchalantly."
  }));
  SetInventory( ([
    C_OBJ + "pants4" :  "wear pants",
    C_OBJ + "shirt5" : "wear shirt",
    C_OBJ + "knife1" : "wield knife"
  ]) );
}
