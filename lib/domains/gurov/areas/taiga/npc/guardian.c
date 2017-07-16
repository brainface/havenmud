//Illura@Haven
//Sept 2009
//guardian
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("guardian");
  SetId( ({ "guardian" }) );
  SetAdjectives( ({ "cold", "iron", "cold-iron", "vigilant" }) );
  SetShort("a vigilant cold-iron guardian");
  SetLong(
    "This guardian is similar to other golems in the tundra, "
    "except that it is much less rusty. An unknown, "
    "antediluvian magic keeps it working. All it knows is "
    "guarding this bridge of ice. Above its cold, azure metal "
    "face is a large piece of zaffre blue metal that emits a "
   "glow, perhaps the source of its power."
  );
  SetClass("fighter");
  SetLevel(80);
  SetRace("golem");
  SetStat("durability", 60, 1);
  SetFirstCommands( ({"wield all"}) );
    SetAction(5, ({
    "!emote turns its head, the stone above its soulless eyes flashing.",
    "!emote moves slightly, making a clamoring hollow noise.",
     "!emote makes an ominous salute to the north.",
                })  );
  SetInventory( ([
    TAIGA_OBJ "iceaxe" : 2,
      ]) );
  SetCorpseItems( ([
    TAIGA_OBJ "skymetal" : 1,
  ]) );
}
