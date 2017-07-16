#include <lib.h>
#include "../goblins.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("medium goblin");
  SetShort("a medium sized goblin");
  SetLong("This medium sized green goblin seems to have risen in "
          "the ranks of the goblin hordes with some ability.  His "
         "girth is matched by his dull green wit.");
  SetGender("male");
  SetRace("goblin");
  SetTown("Kresh");
  SetId( ({ "medium goblin", "goblin" }) );
  SetClass("fighter");
  SetLevel(random(7)+3);
  SetMorality(-25);
  SetCurrency( ([
        "rounds" : random(50),
      ]) );
  SetInventory( ([
     GOBLIN_OBJ + "vest" : "wear vest",
     GOBLIN_OBJ + "spiky_bits" : "wield spiked club in left hand",
    ]) );
 }
