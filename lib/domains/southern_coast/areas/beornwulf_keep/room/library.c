#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a huge library");
    SetLong("This library is huge, with books reaching to the ceiling.  "
          "Someone living in this keep must be quite a scholar.  A draft is "
          "blowing in from an unidentifiable source.");
    SetItems( ([
          ({ "ceiling" }) :
          "The ceiling is at least twenty feet high, but there are books reaching "
          "to the very top.",
          ({ "huge library", "library" }) :
          "The library is home to hundreds, maybe thousands, of books.",
          ({ "wall", "walls" }) :
          "The walls can hardly be seen behind the huge bookcases.",
          ({ "unidentifiable source", "source" }) :
          "You can't see the source of the draft.  It's unidentifiable.",
          ({ "books"}) : 
          "There are books of all sizes, shapes and colors on the bookcases.",
          ({ "bookcases", "bookcase" }) :
          "The walls are lined with bookcases.  The bookcase on the far west "
          "wall is bigger than the rest.",
          ({ "big bookcase" }) :
          "This bookcase dwarfs the others, spanning across the entire wall.",
           ]) );
    SetExits( ([
          "east" : BEORN_ROOM + "hall1.c",
          ]) );
    SetObviousExits("east");
    SetInventory( ([
          BEORN_NPC + "mage.c" : 1,
          ]) );
    SetClimate("indoors");
    SetAmbientLight(45);
}
