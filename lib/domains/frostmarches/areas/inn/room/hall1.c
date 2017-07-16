#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a hallway");
  SetAmbientLight(35);
  SetLong("The sleeping rooms of the Morning Star Inn can be accessed by way "
          "of this hallway.  Like the rest of the inn, there are strong oak "
          "walls and a creaking plank floor.  The main room is south of here "
          "there are rooms to the west and east, and the hallway continues "
          "to the north.");
  SetItems( ([ 
             ({ "creaking plank floor", "creaking floor", "plank floor",
                "floor" }) :
                "It is a simple plank floor.  Though generally well "
                "constructed, it does creak ever so slightly.",
             ({ "strong oak walls", "strong oak wall", "oak walls",
                "oak wall", "strong walls", "strong wall", "walls", "wall" }) :
                "The walls look very strong and will probably last a very "
                "long time.",
             ({ "main room" }) :
                "This is the main room of the inn where people gather to "
                "drink and request a room for the night.",
             ({ "room", "rooms" }) :
                "These are the rooms where people bed down for the night."
             ]) );
  SetListen( ([
              "default" : "The sound of laughter and singing fills the room.",
              ({ "creaking plank floor", "creaking floor", "plank floor",
                 "floor" }) :
                 "Slight creaking can be heard from the plank floor."
              ]) );
  SetObviousExits("north, east, south, west");
  SetClimate("indoors");
  SetExits( ([
             "north" : I_ROOM + "/hall2",
             "east" : I_ROOM + "/room2",
             "south" : I_ROOM + "/main",
             "west" : I_ROOM + "/room1"
             ]) );
}
