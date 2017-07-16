//Illura@Haven
//Sept 2009
//moonweaver
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("moonweaver");
  SetId( ({ "moonweaver" }) );
  SetAdjectives( ({ "ancient" }) );
  SetShort("moonweaver, the ancient");
  SetLong(
    "Moonweaver's slender, maidenly form is composed "
    "of ice shards, mists, and comet trails that wrap themselves "
    "around and around in a metaphysical swirl. Her calm "
    "features and perfectly formed, although impossibly "
    "giant body, give little clue as to her great, though "
    "diminishing powers. Twin chunks of skymetal are "
    "set in the centers of her otherwise colorless, snow-white "
    "eyes."
  );
  SetClass("mystic");
  SetLevel(110);
  SetGender("female");
  SetRace("gargoyle");
  SetAction(5, ({
    "!emote twirls girlishly, her eyes unopening briefly in pleasure.",
     "!emote curtsies gracefully to you.",
    "!emote extends her arms with a smile, as if offering blessing.",
                })  );
 SetSpellBook( ([
                "avalanche" : 100,
                "ice storm" : 100,
                "lunar blast" : 100,
               ]) ); 

  SetCombatAction(50, ({
    "!cast avalanche",
    "!cast ice storm",
    "!cast lunar blast",
    }) );
  SetInventory( ([
    TAIGA_OBJ "staff" : "wield staff",
      ]) );
  SetDie("A distant star crashes into the ocean as the ancient falls.");
}
