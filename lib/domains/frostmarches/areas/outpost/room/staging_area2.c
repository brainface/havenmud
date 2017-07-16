#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside a large tent");
  SetLong(
    "The large wooden palisade continues around the Kylin outpost. Erected in "
    "the west is a large white tent, the entrance for this tent is accessible "
    "from here. Seen in the east, the Durgoroth road heads north to the ruins "
    "of Durgoroth and south through the large wooden gate. A well has been dug "
    "and sits near the entrance to the tent. Like an ever-vigilant sentinel, "
    "a tall tower stands to the north watching over the ruins of Durgoroth." );
  SetAmbientLight(20);
  SetClimate("sub-arctic");
  SetItems( ([
    ({"gate", "entrance" }) : 
    "To the east, a large wooden gate can be seen guarding the Durgoroth road.",
    "road" : 
    "The road, off to the east, runs north to the ruins of Durgoroth and south "
    "to the Durgorth road.",
    ({"ruins", "Durgoroth"}) :
    "The ruins of Durgorth can be seen in the north.",
    ({"outpost", "camp"}) : 
    (: GetLong :),
    ({"palisade", "wall"}) : 
    "This wooden wall, which surrounds the camp, is made of large tree trunks "
    "lashed together.",
    ({"tree", "trunks","trees"}) :
    "Large tree trunks lashed together protect the camp.",
    ({"tent","entrance"}) :
    "A large white tent has been set up to the west. Access can be gained to "
    "the tent from here.",
    ({"tower","sentinel"}) :
    "A tower, towards the north, stands tall watching over the ruins of "
    "Durgoroth.",
    ]) );
  SetItemAdjectives(( [
    "gate"     : ({"large", "wooden"}),
    "outpost"  : ({"inquisitor", "invader", "invaders"}),
    "palisade" : ({"tall", "wooden"}),
    "road"     : ({"durgoroth"}),
    "tree"     : ({"large"}),
    "ruin"     : ({"durgoroth"}),
    "tent"     : ({"large","white"}),
    "tower"    : ({"tall","ever-viligant","viligant"}),
    ]) );
  SetExits( ([
    "north" : OP_ROOM + "staging_area1",
    "east"  : OP_ROOM + "south_gate",
    ]) );
  SetEnters( ([
    "tent" : OP_ROOM + "pray_tent",
    ]) );
  SetSmell( ([
    "default" : "The air is filled with the smell of burning wood.",
    ]) );
  SetListen( ([
    "default" : "Soft chanting can be heard.",
    ]) );
  SetInventory( ([
    OP_NPC + "controller" : 1,
    OP_OBJ + "well"       : 1,
    ]) );
}