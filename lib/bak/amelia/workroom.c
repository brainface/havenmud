#include <lib.h>
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("Amelia's Workroom");
  SetLong("A large window overlooks the muezzin town Soleil, "
          "and a huge sunroof above lets in lots and lots of "
          "light.  A blooming lilac bush "
          "is placed to the southern side of the room, and "
          "little furry things leap around and play on the "
          "floor.  A simple rocking chair sits next to the "
          "window, with a small clipboard floating next to it.");
  SetSmell( ([
               "default" : "The sweet smell of lilacs "
                  "fills the air.",
          ]) );
  SetExits( ([
               "down" : "/domains/staff/staffroom",
    ]) );
  SetInventory( ([
      ]) );
   SetClimate("temperate");
} 
