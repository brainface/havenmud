#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("on an edge of a pit");
  SetLong(
    "The tall palisade protects the outpost to the north. A rampart, which is "
    "reinforcing this section of the wall, is composed of earth and stone "
    "piled up against the palisade. Leading back to the north gate and the "
    "Durgoroth road, a path has been cleared through the snow. In the east, "
    "a large pit has been dug and has large timbers bracing the walls of the "
    "pit. Between the rampart and the north edge of the pit, footprints can "
    "be seen in the mud leading to the northeast.");
  SetAmbientLight(20);
  SetClimate("sub-arctic");
  SetItems( ([
    ({"gate" }) : 
    "To the west, a large wooden gate can be seen guarding the Durgoroth road.",
    "road" : 
    "The road, off to the west, runs north to the ruins of Durgoroth and south "
    "to the Durgorth road.",
    ({"ruins", "Durgoroth"}) :
    "The ruins of Durgoroth can be seen in the north beyond the palisade.",
    ({"outpost", "camp","edge"}) : 
    (: GetLong :),
    ({"palisade", "wall","section"}) : 
    "This wooden wall, which surrounds the camp, is made of large tree trunks "
    "lashed together. It has been strengthened with an earth and stone rampart.",
    ({"tree", "trunks","trees"}) :
    "Large tree trunks lashed together protect the camp.",
    ({"tent","entrance"}) :
    "A large white tent has been set up to the south.",
    ({"pit","pit wall","pit walls"}):
    "The large pit has been dug very deep and has large timbers in the bottom.",
    ({"timber","timbers"}) :
    "There are large wood timbers bracing the pit from collapsing in on itself.",
    ({"snow"}) :
    "The snow is cleared for paths to lead south to a large white tent and to "
    "the west to the Durgoroth road and wooden gate.",
    ({"footprints","prints","footprint","mud"}) :
    "The are footprints in the mud which lead around the north edge of the pit "
    "to the northeast.",
    ]) );
  SetItemAdjectives(( [
  	"gate"     : ({"large", "wooden"}),
    "outpost"  : ({"inquisitor", "invader", "invaders"}),
    "palisade" : ({"tall", "wooden"}),
    "road"     : ({"durgoroth"}),
    "tree"     : ({"large"}),
    "ruin"     : ({"durgoroth"}),
    "tent"     : ({"large","white"}),
    "pit"      : ({"large","construction"}),
    "timber"   : ({"large","wood"}),
    ]) );
  SetExits( ([
    "northeast" : OP_ROOM + "construction_area2",
    "west"      : OP_ROOM + "north_gate",
    "south"     : OP_ROOM + "staging_area4",
    ]) );
  SetSmell( ([
    "default" : 
    "The smell of freshly dug earth fills the air.",
    ]) );
  SetListen( ([
    "default" : 
    "The sound of hammering can be heard in the distance."
    ]) );
  SetInventory( ([
    OP_NPC + "dwarf_worker" : 3,
    ]) );
}