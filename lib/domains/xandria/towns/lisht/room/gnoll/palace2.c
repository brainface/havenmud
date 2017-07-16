// Future addition to include hidden chamber to
// secret elven rebellion... 
// Aless 2011

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
     "This room appears to be used as the workroom of the Pharaoh's many "
     "slaves. Large tables are littered with great vessels of drink and the "
     "half-finished makings of meals. A massive archway leads back towards "
     "the east. Carvings are etched into each wall just like the other Palace "
     "rooms, telling of the history and glory that is the Xandrian Dynasty. "
     "A huge black emblem is carved deeply into the floor stones. "
     );
  SetSmell( ([
     "default" : "The mouthwatering smells of fruits and breads are enough to "
        "make a stomach rumble."
     ]) );
  SetListen( ([
     "default" : "The hushed murmur of daily palace activity is a bit louder here."
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
     ({ "table", "vessel", "vessels", "tables", "makings" }) : "The large tables are "
        "littered with all the components necessary to make a grand meal.",
     ]) );
  SetItemAdjectives( ([
     "palace" : ({ "massive", "stone" }),
     "spire" : ({ "tall", "marble" }),
     "arch" : ({ "stone", "massive", "impressive" }),
     "carving" : ({ "etched" }),
     "emblem" : ({ "huge", "black", "carved" }),
     "wall" : ({ "stone", "etched" }),
     "table" : ({ "large", "great", "half-finished", "grand" }),
     "floor" : ({ "smooth", "stone", "carved" }),
     ]) );
  SetTouch( ([
     "stone" : "The stone of the palace is cool to the touch."
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "east" : LISHT_ROOM "gnoll/palace1",
     ]) );

}
