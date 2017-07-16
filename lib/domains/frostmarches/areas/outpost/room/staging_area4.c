#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside a large tent");
  SetLong(
    "The large wooden palisade continues around the Kylin outpost. Erected in "
    "the east is a large white tent, the entrance for this tent is accessible "
    "from here. Seen in the west, the Durgoroth road heads north to the ruins "
    "of Durgoroth and south through the large wooden gate. To the north, a "
    "large pit can be seen and beyond that the ruins of Durgoroth. The snow "
    "around the tent has been cleared and piled up against the palisade.");
  SetAmbientLight(20);
  SetClimate("sub-arctic");
  SetItems( ([
    ({"gate" }) : 
    "To the west, a large wooden gate can be seen guarding the Durgoroth road.",
    "road" : 
    "The road, off to the west, runs north to the ruins of Durgoroth and south "
    "to the Durgorth road.",
    ({"ruins", "Durgoroth"}) :
    "The ruins of Durgoroth can be seen in the north beyond a large pit.",
    ({"outpost", "camp"}) : 
    (: GetLong :),
    ({"palisade", "wall"}) : 
    "This wooden wall, which surrounds the camp, is made of large tree trunks "
    "lashed together.",
    ({"tree", "trunks","trees"}) :
    "Large tree trunks lashed together protect the camp.",
    ({"tent","entrance"}) :
    "A large white tent has been set up to the east. Access can be gained to "
    "the tent from here.",
    "pit" :
    "A large construction pit can be seen in the north.",
    ({"snow", "pile" }) :
      "The snow is cleared around the tent and piled up against the palisade.",
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
    ]) );
  SetExits( ([
    "north" : OP_ROOM + "staging_area3",
    "west"  : OP_ROOM + "south_gate",
    ]) );
  SetEnters( ([
    "tent" : OP_ROOM + "command_tent",
    ]) );
  SetSmell( ([
    "default" : 
    "The air is filled with the smell of burning wood.",
    ]) );
  SetListen( ([
    "default" : 
    "The sound of hammering can be heard in the distance."
    ]) );
  SetInventory( ([
    OP_NPC + "paladin" : 2,
    ]) );
}