#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(30);
  SetTown("Glimmerdin");
  SetShort("a comfortably furnished chamber");
  SetProperty("no conjuring", 1);
  SetProperty("no teleport", 1);
  SetExits( ([
    "east" : G_ROOM "keep",
    ]) );
  SetInventory( ([
    G_NPC "dorscha" : 1,
    ]) );
  SetLong(
    "This small chamber in the keep is comfortable and filled with "
    "furniture unlike any other in Glimmerdin. The floors are covered "
    "with carpeting, and the walls are lined with books in various "
    "languages. Everything about this small sitting room seems to "
    "suggest comfort and refinement."
    );
  SetItems( ([
    ({ "furniture" }) :
        "The furniture is thick with plush cushions.",
    ({ "cushion", "cushions" }) :
        "The cushions are thick and well stuffed.",
    ({ "floor", "floors" }) :
        "The floor is covered in thick carpet.",
    ({ "carpet", "carpeting" }) :
        "The floor is covered in thick carpet.",
    ({ "book", "books", "wall", "walls", }) :
        "The walls are lined in books both old and new.",
    ]) );
  SetItemAdjectives( ([
    "furniture" : ({ "thick", "plush", }),
    "cushion"   : ({ "thick", "plush", }),
    ]) );
  SetSmell( ([
    "default" : "The scent of roses (of all things) fills the chamber.",
    ]) );
  SetListen( ([
    "default" : "The room seems quieter than most of Glimmerdin.",
    ]) );
}