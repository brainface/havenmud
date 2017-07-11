//
// Beside a pile of rubble
// By Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("beside a pile of rubble");
  SetLong("On this side of the rubble filling the archway,"
    " there is an unusual style of tunnel leading away into"
    " the gloom. There is something strange about the wall. It seems"
    " to be extraordinarily smooth, and glistens with some"
    " form of mucus or slime. Also, the ceiling is very"
    " low; whatever it was that made this passage, it was"
    " not very tall. A hole leads back through the rubble into"
    " the watchtower.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    "tunnel" : (:GetLong:),
    ({"slime","mucus"}) : "This icky stuff coats the walls and"
      " floor and ceiling. It is translucent and slimy.",
    "rubble" : "Stones and debris fill the area, except for a"
      " small hole to the south. The rubble clears a little way"
      " to the north.",
    ({"wall","walls", "moisture"}) :
      "The walls are sticky to the touch, and are saturated by some "
      "kind of slimy excretion.",
    "ceiling" : 
      "The ceiling is only 5 feet high here, and worn down to the "
      "texture of glass.",
    "hole" : "There is a hole leading through the rubble.",
    ]) );
  SetItemAdjectives( ([
    "walls" : ({"glistening","sticky","slimy","smooth"}),
    "ceiling" : "low",
    "slime" : ({"icky","translucent","slimy"}),
    ]) );
  SetSmell( ([
    "default" :
      "The stench of this place is beyond description.",
    "moisture" :
      "The moisture covering the walls smells like vomit.",
    ]) );
  SetListen( ([
    "default" :
      "No sound can be heard here at the moment.",
    ]) );
  SetInventory( ([
    RNQ_OBJ + "snskin.c" : 1,
    ]) );
  SetEnters( ([
    "hole" : RNQ_RM + "rubble1.c",
    ]) );
  SetExits( ([
    "north" : RNQ_RM + "ncor1.c",
    ]) );
}
