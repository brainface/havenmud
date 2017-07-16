#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the spare bedroom");
  SetDayLong("This is just another bedroom. The door to the entryway "
     "is no longer there. It is now laying across the floor. This room "
        "is quite empty. A small bed sits in the corner, while a "
      "small lantern is propped up on a table. It is the only source of light "
        "There is nothing else in the room worth looking at besides another "
        "tiny fireplace set into the wall.");
  SetNightLong("This is just another bedroom. The door to the entryway "
     "is no longer there. It is now laying across the floor. This room "
        "is quite empty. A small bed sits in the corner, while a "
      "small lantern is propped up on a table. It is the only source of light"
        "light in here. There is nothing else in the room worth looking at "
        "besides another tiny fireplace set into the wall.");
  SetAmbientLight(20);
  SetClimate("indoors");
  SetItems( ([
        ({"rooom","bedroom"}) : (:GetLong:),
        ({"door"}) : "This door looks as though it was knocked off "
        "the hinges.  It has been cracked in two and is utterly worthless.",
        ({"bed"}) : "This bed looks fit for one person, a second might "
        "be squeezed in.  This bed is quite small but nice looking.  It has "
        "one big bear skin blanket on it, which looks warm.",
        ({"lantern"}) : "This is obviously the source of light in this room.  "
        "The glass on it is broken but this lantern can still be used.",
        ({"fireplace"}) : "This fireplace is very small, but nice enough to "
        "sit by for warmth.  It's set deep into the wall.",
        ({"wall","walls"}) :  "These walls are solid wood.  There is nothing "
        "on them, they are plain, blunt, and boring.  One wall has a small "
        "indent that plays as a fireplace."
  ]) );
  SetItemAdjectives( ([
        "bed" : ({"warm","small"}),
        "fireplace" : ({"small"}),
        "wall" : ({"plain","blunt","boring"}),
  ]) );
  SetExits( ([
      "east" : L_ROOM + "hallway.c",
  ]) );
  SetSmell( ([
     "default" : "There seems to be no distinct smell in here.",
  ]) );
  SetListen( ([
        "default" : "This room is silent",
  ]) );
}
