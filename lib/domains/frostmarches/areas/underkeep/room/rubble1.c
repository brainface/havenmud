//
// a watchtower
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("a deserted watchtower");
  SetLong("The stairs end here in a squarish room that was probably "
      "used as a watchtower, in the ages past when this place was "
      "still open to the warm light of the sun. Now, the window "
      "which would have offered a grand view of the surroundings "
      "shows merely onto bare rock. To the south, an archway leads "
      "off into what would have been another room, but a cave-in "
      "has filled the arch with rubble.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    ({"room","watchtower"}) : (:GetLong:),
    ({"rock","granite"}) : "The rock looks like granite.",
    ({"walls","wall"}) :
      "The walls are made of stone, cunningly worked to fit without "
      "the use of mortar.",
    ({"rubble"}) :
      "Upon close inspection, it appears that there is a small hole "
      "leading further into the castle.",
    ("window") :
      "All that can be seen is the granite of the solid rock that "
      "lies for miles above.",
    "hole" :
      "The hole leads through the rubble.",
    "stairs" : "A set of stone steps lead back down.",
    ({"archway","arch"}) : "The archway is filled with loose rubble. It"
      " doesn't look too hard to find a way through a small hole,"
      " though."
    ]) );
  SetItemAdjectives( ([
    "walls" : ({"stone","granite"}),
    "room" : ({"squarish","deserted"}),
    ]) );
  SetSmell( ([
    "default" :
      "The air is as musty as a tomb.",
    ]) );
  SetListen( ([
    "default" :
      "No sound can be heard here at the moment.",
    ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
    "down" : RNQ_RM + "tower1.c",
    ]) );
  SetEnters( ([
    "hole" : RNQ_RM + "rubble2.c",
    ]) );
}
