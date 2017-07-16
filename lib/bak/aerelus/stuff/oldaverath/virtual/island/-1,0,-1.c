#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-1,0,-1);
  SetLong("The tunnel walls open up after the sudden twist to the south, "
          "opening up into what looks to be someone, or somethings makeshift "
          "home. A rat eaten cot lies in the center of the open tunnel, "
          "resting just beyond an open grate, through which the steady stream "
          "of refuse is drained. Crude paintings have been etched onto the "
          "walls of the sealed tunnel, depicting various goblins in lewd "
          "acts. An old, rotten table rests near the small makeshift bedding, "
          "supported by loose bricks where it is missing a leg. The slab of "
          "rock that brings this branch of the sewer to an end looks to be "
          "recently constructed.");
  SetItems( ([
     ({"wall","walls"}) : "The dark stone walls are covered with the "
       "same sort of slime as in the rest of the sewers. Etched into "
       "the muck and stone are paintings, or carvings of goblins.",
     ({"painting","paintings","carving","carvings"}) : "These crude etchings "
       "in the tunnels walls, depict goblin like creatures in various "
        "lewd acts.",
     ({"cot","bedding"}) : "This rat eaten cot is not the most pleasant of "
       "beds. Rips and tears in it make it fairly unstable looking, and the "
       "material is stained with dark muck, no doubt from the sewer floors.",
     ({"grate"}) : "Though fairly small, this grate open on the far side "
       "of the room, seems to drain most of the river of sewage.",
     ({"table"}) : "This wood table is rotten from it's years spent in "
       "the damp sewers. It's legs are unsteady and parts of the wood seem "
       "to bulge from years of the moisture seeping into it. Old bricks "
       "support the table on one side, where the leg has already collapsed.",
     ({"slab","rock"}) : "This end of the tunnel looks newly finished, "
       "the slabs of rock that close the tunnel off are much different "
       "from any elsewhere in the tunnel.",
  ]) );
  SetItemAdjectives( ([
     "wall" : ({"stone","dark"}),
     "painting" : ({"crude","lewd"}),
     "table" : ({"old","rotten"}),
     "cot" : ({"makeshift","eaten","rat eaten"}),
     "grate" : ({"open"}),
     ]) );
  SetInventory(
  ([
    AVERATH_NPC + "thief_leader" : 1
  ]) );
  RemoveExit("west");
  RemoveExit("east");
  RemoveExit("north");
}
