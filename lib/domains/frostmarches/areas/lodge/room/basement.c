#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("down in a creepy basement");
  SetDayLong("The raunchy smell of decay and mold lie here. It is quite dark in "
         "here. Except for the light from upstairs. Glass jars have been broken "
        "and spread on the ground. They have apparently fallen off of the broken "
        "shelves that lie haphazardly on the ground. There are stairs leading to the "
        "upstairs and a giant sized trunk lies in the middle of the floor.");
  SetNightLong("The raunchy smell of decay and mold lie here. It is quite dark in "
        "here. Glass jars have been broken and spread on the ground. They have "
        "apparently fallen off of the broken shelves that lie haphazardly on the ground. "
        "There are stairs leading to the upstairs and a giant sized trunk lies in "
        "the middle of the floor.");
  SetAmbientLight(20);
  SetClimate("indoors");
  SetItems( ([
        ({"basement","room"}) : (:GetLong:),
        ({"glass","jar","jars"}) : "The edges of the glass are very rugged and "
        "sharp.  The jars seem to have fallen off of the shelves where they "
        "belong.  Slight bits of dust has collected on this glass.",
        ({"wall","walls"}) : "Nothing interesting is found here.  It's cold and hard. "
        "The walls are so old they have start to peel.",
     ({"ground","floor"}) : "Glass has been spread all around.  Other than "
        "that there is nothing to see here.",
     ({"stair","stairs","staircase"}) : "These stairs do not look very durable. "
        "The wood is decayed and has been eatten away at.  One must be "
        "careful to not put too much weight on here.",
        ({"trunk","chest"}) : "This trunk is open. The bottom of the trunk appears "
        "to have been completely clawed and gnawed at, revealing a pit dug into "
        "the very bowels of Kailie.  The trunk certainly seems large enough to go down in.",
  ]) );
  SetItemAdjectives( ([
        "glass" : ({"sharp","rugged"}),
        "wall" : ({"cold","hard"}),
        "trunk" : ({"large"}),
  ]) );
  SetExits( ([
     "up" : L_ROOM + "mainfloor.c",
  "down" : L_ROOM + "guardroom.c",
  ]) );
  SetInventory( ([
  ]) );
  SetSmell( ([
        "default" : "It smells like dust and mold down here.",
  ]) );
  SetListen( ([
        "default" : "The sounds of screeching rats can be heard.",
  ]) );
}
