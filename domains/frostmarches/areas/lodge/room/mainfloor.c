#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("inside an abandoned lodge");
  SetDayLong("This room is brightly lit by the sunlight from outside. A small "
        "draft of wind comes into this room. Overturned tables and chairs "
        "lie here. This place looks like its been abandoned for years, although "
        "a lit fire is in the fireplace. A plaque is placed above the fire with "
        "what seems to be a head on it. Aside from the disgust of this room, "
      "a very comfortable couch lays against the wall.");
  SetNightLong("This room is dimly lit by the moonlight from outside. A small "
        "draft of wind comes into this room. Overturned tables and chairs "
        "lie here. This place looks like its been abandoned for years, although "
        "a lit fire is in the fireplace. A plaque is placed above the fire with "
        "what seems to be a head on it. Aside from the disgust of this room, "
      "a very comfortable couch lays against the wall.");
  SetAmbientLight(33);
  SetClimate("indoors");
  SetItems( ([
        ({"room"}) : (:GetLong:),
        ({"tables","table"}) : "This table has been roughly overturned.  It "
        "has been broken with a large crack seaming down the middle, "
        "leaving splinters everywhere. This table is of no use.",
        ({"chair","chairs"}) : "These chairs are broken and crushed.  The "
        "legs have been broken off so they can not be sat on.",
        ({"fire"}) : "This fire has been going for awhile. It's very hot. Don't "
        "get too close.",
     ({"fireplace"}) : "This fireplace is chalked in soot.  The fire inside "
        "has obviously been burning for quite some time.  Underneath all "
      "the soot, the fireplace has been built out of stone.",
        ({"plaque","head"}) : "The head on this plaque is one of an Elf. He "
        "was obviously not welcomed here. The look on his face shows a state "
      "of extreme fear, as if he saw something he should not have before being "
      "beheaded. Perhaps something in this very lodge.",
        ({"couch"}) : "This couch looks very comfortable. It looks like one "
        "of the few things in this room not broken. There is enough room for "
        "two on here.",
        ({"wall","walls"}) : "These walls are made out of rough wood.  There "
      "are slight dents and knicks on these walls, someone must have had a "
        "fight here.",
  ]) );
  SetItemAdjectives( ([
        "table" : ({"broken"}),
        "chair" : ({"broken","crushed"}),
        "fire" : ({"hot"}),
      "couch" : ({"comfortable"}),
        "walls" : ({"rough"}),
  ]) );
  SetExits( ([
      "south" : L_ROOM + "outside20.c",
      "down" : L_ROOM + "basement.c",
      "up" : L_ROOM + "hallway.c",
      "east" : L_ROOM + "outside19.c",
      "north" : L_ROOM + "outside18.c",
      "out" : L_ROOM + "outside17.c",  // torak 2013
  ]) );
  SetSmell( ([
        "default" : "Smells of nature overwhelm the area from outside.",
  ]) );
  SetListen( ([
        "default" : "The slight grunting of a creature can be heard.",
  ]) );
}
