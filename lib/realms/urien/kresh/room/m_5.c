// Urien 111513 - Added Day/Night Long
// Climate, Town, Domain, Items, Adjectives
// Kept overall description the same.

#include <lib.h>
#include <domains.h>
#include "../goblins.h"

inherit LIB_ROOM;

int GuildCheck();

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Southern Coast");
  SetTown("Kresh");
  SetShort("a well trodden path");
  SetDayLong("The main path strays off from the apex "
     "to the northwest and leads south, away from a "
     "rather important looking tent. The grass in the "
     "field has been trampled leaving little chance "
     "for fauna to flourish. A small well has been "
     "built next to the path providing full access "
     "to the tent village. The daylight breaks "
     "awkwardly off the brown aura that surrounds "
     "the brown tent.");
  SetNightLong("The main path from the northwest "
     "bends south to a corner in the village. The "
     "ground has been trampled from the nomad "
     "lifestyles and practices. A small well, directly "
     "next to an important looking tent can be "
     "seen along the northeastern portion of the path. "
     "The night shade conflicts with a magical ward "
     "which ebbs in mystery surrounding the brown "
     "tent.");
  SetItems( ([
   ({ "path","village" }): (: GetLong :),
   ({ "ground", "floor" }): "The ground has been trampled "
      "from the nomad inhabitants, leaving little "
      "care for the trampled grass on and around the "
      "path.",
   "path": "The path splits from the apex from the "
      "northwest. It is merely trodden and exposed "
      "soil from the nomad inhabitants. In this "
      "section of the path specifically, it seems "
      "to be more of a gathering place due to the "
      "well water source.",
   ({ "ward","aura" }): "A strange, magical brown aura can be seen "
      "outside the surface of the tent. It refracts "
      "the natural light slightly and wards off "
      "unwanted predators.",
   "field": "The field is mostly barren with little "
      "grass growing along the surface. A path has "
      "been made that dissects the field in two.",
   "grass": "It is dried out and lifeless, leaving "
      "little option for animals to graze.",
   "tent" : "This tent is the home of the proclaimed "
     "Goblin Horde, the Khan's Army.",
    ]) );
  SetItemAdjectives( ([
   "tent" : ({ "heavy", "brown" }),
   "aura": ({ "brown","magic" }),
   "field": ({ "barren" }),
  ]) );
  AddEnter("tent", GOBLIN_TENT "horde", (: GuildCheck :) );
  SetExits( ([
     "northwest" : GOBLIN_ROOM + "m_3",
     "south"     : GOBLIN_ROOM + "m_7",
    ]) );
  SetInventory( ([
      GOBLIN_NPC + "slash_medium" : 3,
      GOBLIN_OBJ "well" : 1,
    ]) );
  SetSmell( ([
      "default" : "The stench of decaying food wafts "
                  "from the south.",
      ]) );
  SetListen( ([
     "default" : "The sounds of goblin  come "
                 "from the south.",
  ]) );
}

int GuildCheck() {
  object who = this_player();
  
  if (who->GetGuild() != "horde" && !creatorp(who)) {
    who->eventPrint("Somehow you just can't muster "+
                    "the courage to enter that tent.");
    return 0;
  }
  return 1;
}
