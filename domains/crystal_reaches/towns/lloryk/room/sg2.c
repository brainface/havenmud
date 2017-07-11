#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("south of an intersection");
  SetExits( ([
     "north" : LLORYK + "room/hb4",
     "south" : LLORYK + "room/sg1",
     ]) );
  SetLong("On to the north, a three way intersection connects two of "
          "the villages three roads. The path continues to the north "
          "and south from here.  Far off to the south, the path leads "
          "to the southern gate out of the village.  Rolling hills "
          "surround the town and make for excellent farmland. Sitting "
          "next to the path is a medium sized martial looking building.");
  SetListen( ([
     "default" : "The bleating of sheep and mooing of cows is all around.",
     ]) );
  SetSmell( ([
     "default" : "The smells of farmland are a strange mix of the pleasant "
                 "and unpleasant.",
     ]) );  
  SetItems( ([
    ({ "hill", "hills", "hillside" }) : "The rolling hills of Lloryk "
                                        "stretch out in all directions.",
    ({ "building" }) : "This building is the home of the Shire Guard.",
    ]) );
  SetItemAdjectives( ([
    "hill"   : ({ "rolling", }),
    "building" : ({ "medium", "sized", "martial", "looking" }),
    ]) );
  SetEnters( ([
    "building" : LLORYK "room/guards",
    ]) );          
}
