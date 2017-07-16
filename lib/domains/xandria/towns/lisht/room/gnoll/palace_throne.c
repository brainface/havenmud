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
     "A massive archway leads back back out to the Palace entrance. "
     "Carvings are etched into each wall, telling of the history and glory that "
     "is the Xandrian Dynasty. A huge black emblem is carved deeply into "
     "the floor stones. It is cool and luxurious in this part of the Palace."
     );
  SetSmell( ([
     "default" : "The smell of sweet incense lingers here."
     ]) );
  SetListen( ([
     "default" : "The hushed murmur of daily palace activity is quiet here."
     ]) );
  SetItems( ([
     ({ "room", "area", "palace" }) : (:GetLong:),
     ({ "spire", "spires" }) : "These tall marble spires stretch from floor to "
        "ceiling.",
     ({ "archway", "arch", "arches", "archways" }) : "The stone archways connect "
        "the palace rooms together as well as leading from the inside to the "
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
     LISHT_NPC "pharaoh" : 1,
     LISHT_OBJ "throne" : 1,
     LISHT_NPC "pal_slave" : 2,
     ]) );
  SetExits( ([
     "east" : LISHT_ROOM "gnoll/palace_ent",
     ]) );

}
