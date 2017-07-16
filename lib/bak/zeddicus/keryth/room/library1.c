#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create()
{
  room::create();
  SetShort("the Library");
  SetTown("Keryth");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetLong("The Keryth Library envelops the entire northern wing of this "
          "building.  This room is lined with tall bookshelves that stretch "
          "to the ceiling.  There is one exit to the south which leads to "
          "the town hall.");

  SetItems( ([
    ({ "library", "room", "wing", "building" }) :
       (:GetLong:),
    ({ "floor", "carpet" }) :
       "The library is carpeted in a several area rugs. Otherwise, there is "
       "a hardwood floor.",
    ({ "rug", "rugs" }) :
       "Large area rugs occupy the space between bookshelves and protect the "
       "wooden floor from being scratched.",
    ({ "bookshelf", "bookshelves" }) :
       "The bookshelves are lined solidly with books.",
    ({ "book", "books", "page", "pages" }) :
       "The books are all leatherbound, and some look very fragile.  Many "
       "ancient secrets are pressed between the pages."
  ]) );

  SetExits( ([
    "out"  : K_ROOM "main_04",
    "east" : K_ROOM "library2"
  ]) );

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
}
