//Illura@Haven
//Sept 2009
//vanguard
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("vanguard");
  SetId( ({ "vanguard" }) );
  SetAdjectives( ({ "cold", "iron", "cold-iron", "ancient" }) );
  SetShort("a vanguard to the ancients");
  SetLong(
    "The stern golem hulks as large as the ancient tundra "
    "spirits themselves, made entirely of blue-tinged "
    "ice-steel, harder than diamond. Ancient magic emanating "
    "from the zaffre blue skymetal above its featureless face "
    "keeps it from falling apart from generation to generation. "
    "It knows no other task than the endless guardianship "
    "of the ancients."
  );
  SetClass("fighter");
  SetLevel(90);
  SetRace("golem");
  SetStat("durability", 70, 1);
    SetAction(5, ({
    "!emote turns its head, the stone above its soulless eyes flashing.",
    "!emote moves slightly, making a clamoring hollow noise.",
    "!emote makes an ominous salute to the ancients.",
                })  );
  SetInventory( ([
    TAIGA_OBJ "iceaxe" : "wield axe",
      ]) );
  SetCorpseItems( ([
    TAIGA_OBJ "/skymetal" : 1,
  ]) );
  SetDie("As it dies, the vanguard lets loose a keening noise, knowing it has failed.");
}
