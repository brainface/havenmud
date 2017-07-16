//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Along a path");
  SetTown("Keryth");
  SetDomain("FrostMarches");
  SetClimate("arctic");
  SetLong("The cleared road leads back to the east.  Frosted trees line the "
          "edge of the road, and ground beneath looks frozen.  In the snow, "
          "there is the cemetery to the south, and a small building to the "
          "north. There is a tall structure to the west.");
  SetItems( ([
    ({ "path" }) : (:GetLong:),
    ({ "cleared road", "road" }) :
       "The snow has been cleared away along the road to make it "
       "navigatable.",
    ({ "cold gloomy cemetery", "cold cemetery", "cemetery",
       "gloomy cemetery" }) :
       "The cemetery is segregated by a short picket fence.  It looks gloomy "
       "and cold.",
    ({ "short white picket fence", "short picket fence", "fence",
       "short fence", "white picket fence", "white fence", "picket fence" }) :
       "The short fence looks as though it is virtually abandoned.  The "
       "white paint is peeling, and some of the fence posts have sunken into "
       "the ground or been knocked over.",
    ({ "white peeling paint strips", "white peeling paint", "white paint",
       "peeling paint", "white paint strips", "peeling paint strips", "paint",
       "strips", "white peeling paint strip", "white paint strip",
       "peeling paint strip", "peeling strip", "peeling strips",
       "paint strip", "paint strips", "strip" }) :
       "The white paint is peeling off in long strips.",
    ({ "sunken fence posts", "fence posts", "sunken fence post",
       "sunken posts", "sunken post", "fence post", "posts", "post" }) :
       "The posts of the white picket fence are in disarray; many have been "
       "knocked down.",
    ({ "brown dirt ground", "brown ground", "dirt ground", "dirt",
       "frozen ground", "ground" }) :
       "The brown dirt ground has been frozen for some time.",
    ({ "small wooden building", "small building", "wooden building",
       "building", "healer hut", "hut" }) : 
       "A small wooden building stands to the north that houses the only "
       "healer in town.",
    ({ "frosted deciduous trees", "frosted tree", "trees", "tree",
       "frosted deciduous tree", "deciduous trees", "deciduous tree",
       "large frozen drops of water", "large frozen drops",
       "large frozen drop", "large drops", "large drop", "frozen drops",
       "frozen drop", "drops", "drop", "drops of water", "drop of water",
       "large drops of water", "large drop of water", "frozen drops of water",
       "frozen drop of water", "long spindly branches", "long spindly branch",
       "spindly branches", "spindly branch", "branches", "branch" }) :
       "Large frozen drops of water cling to the long, spindly branches of "
       "the deciduous trees on the side of the road.",
    ({ "tall structure", "structure", "tall building", "building", "temple",
       "church" }) :
       "This tall building serves as the temple of Soirin in Keryth."
  ]) );
  SetExits( ([ "east" : K_ROOM + "/road3" ]) );
  SetEnters( ([
    "cemetery" : K_ROOM + "/cemetery",
    "healer hut" : K_ROOM + "/healer_hut.c",
    "church"    : K_ROOM + "/temple"
  ]) );
  SetInventory( ([ K_NPC + "/rogue" : 1 ]) );
  SetSmell( ([
    "default" : "The sharp smell of the cold air pierces the senses."
  ]) );
}
