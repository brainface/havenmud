#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a large cave");
  SetLong("The remains of a large fire sit in the center of the cave.  Small "
          "rocks and pebbles are scattered along the floor.  Towards the back "
          "of the cave, a few large boulders lie piled up.  A path seems to "
          "lead out of the cave towards a wooded area.  This cave is a "
          "resting place of some sort.");
  SetListen( ([ 
  	"default" : "A rumbling from behind the boulders is barely audible."
  	]) );
  SetSmell( ([ 
  	"default" : "An awful stench assaults your nostrils."
  	]) );
  SetItems( ([
        ({ "this cave","cave","resting place","place" }) :
        (: GetLong() :),
        ({ "small path","path","wooded area","area" }) :
        "A small path leads out of the cave towards a wooded area to the east.",
        ({ "fire remains","remains","large fire","fire",
        "center of cave","center" }) :
        "All that is left of a hastily put out fire can be seen "
        "at the center of the cave.",
        ({"small rocks","small pebbles","rocks","pebbles",
        "small rock","small pebble","rock","pebble","floor of cave",
        "floor" }) :
        "Small rocks and pebbles litter the floor of the cave.",
        ({ "few large boulders","few boulders","large boulders",
        "boulders","large boulder","boulder","back of cave","back"}) :
        "The boulders piled up at the back of the cave seem to be "
        "blocking something."
        ]) );
  SetExits( ([
        "out" : F_ROOM "forest5"
        ]) );
  
}
