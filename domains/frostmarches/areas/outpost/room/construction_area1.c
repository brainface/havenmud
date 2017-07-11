#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside a palisade");
  SetLong(
    "The tall palisade protects the outpost to the north and west before heading "
    "south. Reinforcing this section of the wall is a rampart, which is composed "
    "of earth and stone piled up against the palisade. Through the snow, a path "
    "has been cleared and leads to the southeast towards the center of the "
    "outpost.  A tall wooden tower stands to the south, like a sentinel watching "
    "over the ruins of Durgoroth.");
  SetAmbientLight(10);
  SetClimate("sub-arctic");
  SetItems( ([
    ({"ruins", "Durgoroth"}) :
    "The ruins of Durgoroth can be seen in the north beyond the palisade.",
    ({"outpost", "camp"}) : 
    (: GetLong :),
    ({"palisade", "wall","section"}) : 
    "This wooden wall, which surrounds the camp, is made of large tree trunks "
    "lashed together. It has been strengthened with an earth and stone rampart.",
    ({"tree", "trunks", "trees"}) :
    "Large tree trunks lashed together protect the camp.",
    ({"earth", "stone", "rampart"}) : 
    "Earth and stone have been piled up against the wooden palisade strengthening "
    "it.",
    ({"tower", "sentinel"}) :
    "A tall dark wooden tower stands to the south watching over the ruins.",
    ({"ruins","ruin", "Durgoroth","city"}) :
    "Over the wooden palisade and to the north stands the ruins, once called the"
    "city of Durgoroth",
    ({"path","snow"}) :
    "Through the snow, a path has been cleared which leads to the southeast.",
    ]) );
  SetItemAdjectives(( [
    "outpost"  : ({"inquisitor", "invader", "invaders"}),
    "palisade" : ({"tall", "wooden","large"}),
    "tower"    : ({"tall", "dark", "wooden"}),
    "tree"     : ({"large"}),
    "ruin"     : ({"durgoroth"}),
    ]) );
  SetExits( ([
    "southeast" : OP_ROOM + "staging_area1",
    ]) );
  SetSmell( ([
    "default" : 
    "The air is filled with the smell of freshly dug earth.",
    ]) );
  SetListen( ([
    "default" : 
    "The soft sound of hammering can be heard in the distance."
    ]) );
  SetInventory( ([
    OP_NPC + "dwarf_worker"  : 2,
    OP_NPC + "dwarf_paladin" : 2,
    ]) );
}