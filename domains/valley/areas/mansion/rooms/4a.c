/* a library
     kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small library");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This small library is full of books and looks as though it "
          "is used quite often. There are a few people from the party "
          "are gathered here and appear to be involved in a very intense "
          "discussion. The lamps give off a dim light which gives the room "
          "a welcoming feeling.");
  SetItems( ([
     ({ "small library", "library", "room" }) : (:GetLong:),
     ({ "books", "book" }) : 
	    "The books here look as though they are read quite often.",
     ({ "people", "person" }) : 
	    "The people seem to be discussing the rumor of Kysanth the Black Dragon.",
     ({ "lamps", "lamp" }) : "The lamps provide enough light to read by.",
     ]) );
  SetExits( ([
       "west" : MANSION_ROOMS + "3a",
          ]) );
  SetInventory( ([
        MANSION_NPC + "owner_female" : 1,
             ]) );
  SetSmell( ([
         "default" : "The room smells of books and old paper.",
           ]) );
  SetListen( ([
         "default" : "The sounds of the party outside mix with the sound "
                     "of the ongoing discussion of Kysanth.",
           ]) );
  }
