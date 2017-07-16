#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a hallway");
  SetAmbientLight(35);
  SetLong("The hallway ends here.  The northern end of the ceiling appears to "
          "be grey with soot and the floor has ash marks all over it.  There "
          "are rooms to the west, north, and east with the hall leading back "
          "to the south.");
  SetSmell( ([
             "default" : "There is a faint scent of burning wood here."
             ]) );
  SetItems( ([ 
             ({ "ceiling", "end", "northern end", "soot" }) :
                "There is quite a bit of soot deposited on the ceiling "
                "here.  Such an occurance is common near a fireplace or "
                "a wood burning stove.",
             ({ "floor", "wood ash", "ash marks", "ash", "marks" }) :
                "Wood ash is evident on the floor just in front of the room "
                "to the north.",
             ({ "room", "rooms" }) :
                "These are the rooms where people bed down for the night.",
             ({ "steep staircase", "wooden staircase", "stairs", 
                "staircase" }) :
                "This is a steep wooden staircase leading to the second floor."
             ]) );
  SetClimate("indoors");
  SetExits( ([
             "north" : I_ROOM + "/family",
             "east" : I_ROOM + "/room4",
             "south" : I_ROOM + "/hall1",
             "west" : I_ROOM + "/room3",
             "up" : I_ROOM + "/hall3"
             ]) );
}
