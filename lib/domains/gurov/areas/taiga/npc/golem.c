//Illura@Haven
//Sept 2009
//golem
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("golem");
  SetId( ({ "golem" }) );
  SetAdjectives( ({ "cold", "iron", "cold-iron" }) );
  SetShort("a cold-iron golem");
  SetLong(
    "This golem is made of iron tinged with faint blue swirls, "
    "a heavy piece of machinery that clatters and scrapes "
    "rustily along. Some unknown ancient magic holds it "
    "together. Above its cold metal face is a large piece of "
    "zaffre blue metal that emits a glow, perhaps the source "
    "of its power."
  );
  SetClass("fighter");
  SetLevel(70);
  SetRace("golem");
  SetStat("durability", 50, 1);
  SetFirstCommands( ({"guard north", "wield all"}) );
    SetAction(5, ({
    "!emote menaces toward you.",
    "!emote moves slightly, and rust flakes off of it.",
    "!makes an ominious salute to the north.",
                })  );
  SetInventory( ([
    TAIGA_OBJ "iceaxe" : 2,
      ]) );
  SetCorpseItems( ([
     TAIGA_OBJ "skymetal" : 1,
  ]) );
}
