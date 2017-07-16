#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside a wooden tower");
  SetLong(
    "The large wooden palisade stands to the north protecting the outpost from "
    "anything that may wander out of the ruins of Durgoroth. Piled up against "
    "the wooden wall is earth and stone, which forms a rampart, to reinforce "
    "this section of the wall. A wooden tower stands tall like a wooden sentinel "
    "watching for danger from the ruins.  Paths in the snow lead south towards "
    "some tents, northwest following the wall, and east towards the outpost "
    "gate and the road to the ruins." );
  SetAmbientLight(20);
  SetClimate("sub-arctic");
  SetItems( ([
    "gate" : 
    "There is a large wooden gate to the east guarding the road to the ruins of "
    "Durgoroth",
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
    "road" : 
    "The road, towards the east, runs north towards the ruins of Durgoroth and "
    "south to the Durgoroth road.",
    ({"tower", "sentinel"}) :
    "A tall dark wooden tower stands here watching over the ruins.",
    ({"ruins","ruin", "Durgoroth","city"}) :
    "Over the wooden palisade and to the north stands the ruins, once called the"
    "city of Durgoroth",
    ({"path","paths","snow"}) :
    "Three paths have been cleared in the snow. One heads northwest, another "
    "towards the gate and road to the east, and the third leads south to some "
    "tents.",
    ({"tent","tents"}) :
    "The white canvas tents have been erected south of here.",
    ]) );
  SetItemAdjectives(( [
  	"gate"     : ({"large", "wooden"}),
    "outpost"  : ({"inquisitor", "invader", "invaders"}),
    "palisade" : ({"tall", "wooden","large"}),
    "tower"    : ({"tall", "dark", "wooden"}),
    "road"     : ({"durgoroth"}),
    "tree"     : ({"large"}),
    "ruin"     : ({"durgoroth"}),
    "tent"     : ({"white","canvas"}),
    ]) );
  SetExits( ([
    "south"     : OP_ROOM + "staging_area2",
    "east"      : OP_ROOM + "north_gate",
    "northwest" : OP_ROOM + "construction_area1",
    ]) );
  SetEnters( ([
    "tower" : OP_ROOM + "watch_tower1",
    ]) );    
  SetSmell( ([
    "default" : "The smell of fresh cut wood fills the air.",
    ]) );
  SetListen( ([
    "default" : "The sound of hammering can be heard in the distance.",
    ]) );
  SetInventory( ([
    OP_NPC + "dwarf_paladin" : 2,
    ]) );
}