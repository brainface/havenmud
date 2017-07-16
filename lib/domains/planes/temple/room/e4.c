/*  Lamrani Temple, East Hallway, Room 4 */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("lower plane", 1);
  SetClimate("indoors");
  SetShort("a large open chamber");
  SetAmbientLight(35);
  SetExits( ([
     "north" : "e3",
    ]) );
  SetSmell( ([
      "default" : "The air is oddly clean and scentless.",
    ]) );
  SetListen( ([
      "default" : "A vague form of light music can be heard.",
    ]) );
  SetLong("This chamber is a large room, opening much larger than "
          "the hallway to the north. The floor here is a solid black, "
          "with nothing of description on it, only the faint reflection "
          "of the walls of the room. Unlike the hallway, the walls of "
          "the room are free of symbols or scenes.");
  SetItems( ([
    "floor" : "The floor is a solid black, looking almost like a night sky.",
   ({ "wall", "walls" }) : "The walls are white with nothing cluttering "
                           "them.",
    ]) );
  SetInventory( ([
      TEMPLE_NPC "lamrani2" : 1,
      TEMPLE_NPC "lamrani1" : 3,
    ]) );
 }
