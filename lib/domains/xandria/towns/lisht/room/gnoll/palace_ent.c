#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;
inherit LIB_TOUCH;

static void create() {
  ::create();
  
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("within the Palace of the Pharaoh");
  SetLong(
     "Tall marble spires stretch to the ceiling in this massive stone palace. "
     "A massive archway leads out back on to the Pharaoh's Road, but inside "
     "it is cool and luxurious. Carvings are etched into each wall, telling "
     "the history and glory that is the Xandrian Dynasty. A huge black emblem "
     "is carved deeply into the floor stones. To the west is the throne room of "
     "the great Pharaoh, and to the north an archway leads further into the "
     "Palace."
     );
  SetSmell( ([
     "default" : "The scents of cakes and incense from the bazaar waft in on "
        "the breeze."
     ]) );
  SetListen( ([
     "default" : "The hustle and bustle of the bazaar can be faintly heard here."
     ]) );
  SetItems( ([
     ({ "room", "area", "palace" }) : (:GetLong:),
     ({ "spire", "spires" }) : "These tall marble spires stretch from floor to "
        "ceiling.",
     ({ "archway", "arch", "arches" }) : "The stone archway connects the "
        "palace rooms together as well as leading from the inside to the "
        "outside. They are impressive architecture.",
     ({ "carving", "carvings", "heiroplyphs" }) : "These heiroglyphs detail "
        "the glory and history of Xandria.",
     ({ "emblem" }) : "This is the symbol of the Xandrian Dynasty, an image "
        "looking much like an eye with black makeup lining it and staring "
        "out upon the world.",
     ({ "wall", "walls" }) : "The stone walls are etched with intricate carvings.",
     ({ "floor", "ground" }) : "The smooth stone floor bears a huge black emblem.", 
     ]) );
  SetItemAdjectives( ([
     "palace" : ({ "massive", "stone" }),
     "spire" : ({ "tall", "marble" }),
     "arch" : ({ "stone", "massive", "impressive" }),
     "carving" : ({ "etched" }),
     "emblem" : ({ "huge", "black", "carved" }),
     "wall" : ({ "stone", "etched" }),
     "floor" : ({ "smooth", "stone", "carved" }),
     ]) );
  SetTouch( ([
     "stone" : "The stone of the palace is cool to the touch."
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "west" : LISHT_ROOM "gnoll/palace_throne",
     "north" : LISHT_ROOM "gnoll/palace1",
     "out" : LISHT_ROOM "gnoll/pr3",
     ]) );
}
