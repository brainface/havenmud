#include <lib.h>
#include "../rook.h"

inherit LIB_ROOM;

int CheckBlock(string dir);
 
static void create() {
  room::create();
  
  SetShort("hall of statues");
  SetDayLong("This room appears to of been viewing hall of some "
    "sort.  There are pedastals and little carved out niches in "
    "walls and the floor is paved in bricks.  A small amount of "
    "light filters in from an opening in the ceiling of the room "
    "to the northwest.");
  SetNightLong("This room appears to of been viewing hall of some "
    "sort.  There are pedastals and little carved out niches in "
    "walls and the floor is paved in bricks.  There is no natural "
    "lighting in this room.");
  SetItems( ([
    ({"room","hall"}) : (:GetLong:),
    ({"pedastals","niches","niche","pedastal"}) : "The pedastals "
      "are large and seem to built for holding a considerable "
      "amount of weight.  They are sitting in little carved out "
      "niches in the wall as though to display something.",
    ({"wall","walls","floor","brick","bricks"}) : "The walls are "
      "made of a dull grey stone while the floor is paved in the "
      "same type of stone that has been cut into small bricks.",
    ({"light"}) : (query_night() ? "There is no light inside "
      "the sinkhole." : "The light filters ever so slightly from "
      "the room to the northwest."),
    ({"opening","ceiling"}) : "There appears to be an opening "
      "in the ceiling of the room to the northwest.",
  ]) );
  SetItemAdjectives( ([
    "hall" : ({"viewing"}),
    "niche" : ({"little","carved"}),
    "floor" : ({"paved"}),
  ]) );
  SetAmbientLight((query_night() ? SetAmbientLight(0) : 
  SetAmbientLight(10) ));
  SetClimate("indoors");
  SetExits( ([
    "northwest" : R_ROOM + "lair1",
  ]) );
  AddExit("south", R_ROOM + "lair3", (: CheckBlock :));
  SetInventory( ([
    R_NPC + "statue" : 16,
  ]) );
  SetSmell( ([
    "default" : "The room smells of mold and dust.",
  ]) );
  SetListen( ([
    "default" : "Very faint sounds of the forest come from "
      "the northwest.",
  ]) );
}

int CheckBlock(string dir) {
  if(present("statue"))
  {
    message("system",
      "The statues block your exit.",this_player());
  return 0;
  }
  return 1;
}
