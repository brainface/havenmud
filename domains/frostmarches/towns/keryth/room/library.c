//coded by Syra 11/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Town's Library");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(55);
  SetLong("The Keryth Library envelops the entire northern wing of this "
          "building.  This room is lined with tall bookshelves that stretch "
          "to the ceiling.  There is one exit to the south which leads to "
          "the town hall.");
  SetItems( ([
    ({ "keryth library", "library", "room", "northern wing", "wing",
       "building" }) :
       (:GetLong:),
    ({ "hardwood floor", "floor", "carpet" }) :
       "The library is carpeted in a several area rugs. Otherwise, there is "
       "a hardwood floor.",
    ({ "large area rugs", "large area rug", "area rugs", "area rug",
       "large rugs", "large rug", "rugs", "rug", "floor" }) :
       "Large area rugs occupy the space between bookshelves and protect the "
       "wooden floor from being scratched.",
    ({ "tall bookshelves", "tall bookshelf", "bookshelf", "bookshelves" }) :
       "The bookshelves are lined solidly with books.",
    ({ "leatherbound books", "leatherbound book", "books", "book", "pages",
       "page" }) :
       "The books are all leatherbound, and some look very fragile.  Many "
       "ancient secrets are pressed between the pages."
  ]) );
  SetExits( ([ "south" : K_ROOM + "/townhall" ]) );
  SetListen( ([
    "default" :
       "The only sound that can be heard in the library is the faint "
       "ruffling of pages and the padded sound of feet across the floor.",
    ({ "floor", "feet" }) :
       "The rhythmic thudding of a determined pace can be heard when someone "
       "presses their ear to the floor.",
    ({ "books", "pages" }) :
       "The pages sound like a bird's wings fluttering in the wind."
  ]) );
  SetSmell( ([
    "default" : "The musty scent of old books is prevalant here."
  ]) );
  SetInventory( ([
    K_NPC + "/evoker" : 1,
    K_NPC + "/linguist" : 1,
    K_NPC + "/enchanter" : 1
  ]) );
}
