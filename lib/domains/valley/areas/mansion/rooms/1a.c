/* the den in the mansion
     kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a well lit den");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("The den is full of bookshelves and lamps. A large desk stands "
          "in the middle of the room with a large chair behind it. "
          "The room is quite intimidating and looks as though much "
          "business is conducted here on a regular basis.");
  SetExits( ([
       "east" : MANSION_ROOMS + "2a",
             ]) );
  SetItems( ([
     ({ "large desk", "desk" }) : 
		"The large oak desk looks as if it could seat several people.",
     ({ "large chair", "chair" }) : "The chair looks quite comfortable.",
     ({ "bookshelves", "bookshelf", "shelves", "shelf" }) : 
	    "These shelves are full of books.",
     ({"books", "book" }) : "Some of these books look quite old.",
     ({ "lamps", "lamp" }) : 
	    "The lamps are made of stained-glass and appear quite expensive.",
     ({ "stained-glass", "glass"}) : 
	    "The glass is several different colors and gives off radiant light.",
     ({ "radiant light", "light" }) : "The light fills the room splendidly.",
     ]) );
  SetItemAdjectives( ([
       "large desk" : ({ "oak" }),
       "large chair" : ({ "comfortable" }),
       "books" : ({ "old"}),
                   ]) );
  SetSmell( ([
      "default" : "The rooms smells of ink and parchment.",
          ]) );
  SetListen( ([
      "default" : "The music from the party is very soft here.",
              ]) );
  SetInventory( ([
      MANSION_NPC + "owner_male" : 1,
               ]) );
  }
