#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside a wooden gate");
  SetLong("The large wooden gate is the entrance to the outpost of the Inquisitors "
          "of Kylin. A tall palisade surrounds the invaders camp which "
          "supports the gate. The ground, which cannot be distinguished from "
          "the snow and the earth, is frozen solid. Along the side of the road sits "
          "a large campfire. There are tents to the east and west. The road "
          "leads north towards the northern gate of the outpost and towards the "
          "south back to the Durgoroth road." );
  SetAmbientLight(40);
  SetClimate("sub-arctic");
  SetItems( ([
    ({"gate", "entrance" }) : 
    "This large wooden gate guards the Durgoroth road.",
    "northern gate" : 
    "The northern gate can be seen north along the road protecting the camp.",
    ({"outpost", "camp"}) : 
    (: GetLong :),
    ({"palisade", "wall"}) : 
    "This wooden wall, which surrounds the camp, is made of large tree trunks "
    "lashed together.",
    ({"tree", "trunks","trees"}) :
    "Large tree trunks lashed together protect the camp.",
    ({"ground", "snow","earth"}) : 
    "The ground is frozen from the cold climate. The snow on the ground cannot "
    "be distinguished from the frozen earth.",
    ({"campfire","fire"}) : 
    "The campfire along the side of the road keeps the invaders warm in this cold "
    "climate.",
    "road" : 
    "The road runs north towards the ruins of Durgoroth and south to the Durgorth road.",
    ({"tent","tents"}) :
    "There are tents east and west of the here.",
    ]) );
  SetItemAdjectives(( [
  	"gate"     : ({"large", "wooden"}),
    "outpost"  : ({"inquisitor", "invader", "invaders"}),
    "palisade" : ({"tall", "wooden"}),
    "ground"   : ({"solid", "frozen"}),
    "campfire" : ({"large"}),
    "road"     : ({"durgoroth"}),
    "tree"     : ({"large"}),
    ]) );
  SetExits( ([
    "north" : OP_ROOM + "north_gate",
    "east"  : OP_ROOM + "staging_area4",
    "west"  : OP_ROOM + "staging_area2",
    "south" : FROSTMARCHES_VIRTUAL "durgorothroad/-10,15", 
    ]) );
  SetSmell( ([
    "default" : "The air is filled with the smell of burning wood.",
    ]) );
  SetListen( ([
    "default" : 
    "The snapping and popping sound of burning wood can be heard in the background."
    ]) );
  SetInventory( ([
    OP_NPC + "kylin_effigy" : 1,
    OP_NPC + "inquisitor"   : 2,
    ]) );
}