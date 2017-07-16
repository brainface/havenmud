#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a damaged room");
  SetAmbientLight(35);
  SetLong("This room has extensive damage, as if two large angry orcs had a "
          "fight here.  The bedframe in the corner has been completely "
          "smashed, there are craters all over the floor, and several holes "
          "in each wall.  This room will probably not be used for a very "
          "long time.");
  SetItems( ([ 
             ({ "craters", "crater" }) :
                "The craters are everywhere in the floor, making it "
                "hazardous to walk through the room.",
             ({ "walls", "wall", "holes", "hole" }) :
                "The walls are badly damaged with many holes.  Someone must "
                "have punched them in anger several times.",
             ({ "cratered floor", "floor" }) :
                "The floor is quite broken, like two large orcs took turns "
                "body slamming each other here.",
             ({ "smashed bedframe", "broken bedframe", "smashed frame",
                "broken frame", "bedframe", "bed", "frame" }) :
                "Further inspection of the bedframe reveals nothing more."
             ]) );
  SetObviousExits("west");
  SetExits( ([ "west" : I_ROOM + "/hall1" ]) );
  SetClimate("indoors");
}
