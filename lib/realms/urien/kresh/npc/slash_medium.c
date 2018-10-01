#include <lib.h>
#include "../goblins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("medium goblin");
  SetShort("a medium sized goblin");
  SetLong("This medium sized green goblin seems to have risen in "
          "the ranks of the goblin hordes with some ability.  His "
         "girth is matched by his dull green wit.");
  SetFriends( ({ "goblin" }) );
  SetGender("male");
  SetRace("goblin");
  SetId( ({ "medium goblin", "goblin" }) );
  SetClass("fighter");
  SetMorality(-50);
  SetLevel(random(5)+1);
  SetCurrency( ([
        "rounds" : random(50),
      ]) );
  SetInventory( ([
     GOBLIN_OBJ + "vest" : "wear vest",
     GOBLIN_OBJ + "slashy_thing" : "wield shortsword in left hand",
    ]) );
 }
