//
// a store room
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a hidden store room");
  SetLong(
    "This room was a hidden store room for the sentries, where they would"
    " keep contraband and personal items hidden from the sergeant-at-arms."
    " It is very small, only about six feet square, and is very dirty."
    " The encrusted dirt covering the wooden floor has built up over the"
    " centuries, and climbed up the walls and even reached the ceiling"
    " in places. A red velvet curtain covers the exit back to the east.");
  SetClimate("underground");
  SetAmbientLight(5);
  SetItems( ([
    "curtain" : "The curtain is of crushed red velvet and covers the"
      " exit back to the east.",
    ({"wood","walls","ceiling"}) : "The wooden walls and ceiling are"
      " rotten and ridden with woodworm. They are covered in dirt.",
    "floor" : "The wooden floor looks like it could give way at any moment.",
    "room" : (:GetLong:),
    ({"items","contraband","feather","junk","picture of a sweetheart",
      "picture","stuff"}) :
      "The stuff that was worth a lot to those soldiers is not worth"
      " anything now, even if it ever was--a picture of a sweetheart,"
      " a lucky feather, and similar bits of junk.",
    "dirt" : "Dirt has formed a layer over the wooden floor like"
      " an earthen carpet."
    ]) );
  SetItemAdjectives( ([
    "wood" : "dirty",
    "floor" : ({"wooden","dirty"}),
    "room" : ({"hidden","store"}),
    "items" : "personal",
    "dirt" : "encrusted",
    "curtain" : ({"crushed","red","velvet"}),
    ]) );
  SetListen( ([
    "default" : "The wooden floor creaks alarmingly.",
    "floor" : "The wooden floor creaks alarmingly.",
    ]) );
  SetSmell( ([
    "default" : "It smells of mothballs in here.",
    ]) );
  SetInventory( ([
    RNQ_OBJ + "rusty_sword" : 2,
    RNQ_OBJ + "locket" : 1,
    ]) );
  SetExits( ([
    "east" : RNQ_RM + "quarters",
    ]) );
}
