/*   Averath Field Old Hut
 *   Created BY: Ohtar
 */

#include <lib.h>
#include "../avb.h"

inherit LIB_ROOM;


static void create() {
room::create();
SetShort("inside a small hut");
SetClimate("indoors");
SetLong("The inside of this small hut leaves much to be desired. "
        "Each wall is mostly rotted away and completely bare. "
        "There are no furnishings of any kind in this room. "
        "Covered in mostly dried up dirt is the termite eaten "
        "floor. Drooping down above is all that is left of the "
        "decaying ceiling. The door is hanging on one last hinge "
        "that is barely holding. A small window is framed into "
        "the front of the house however, there is no glass left "
        "in it. The only exit is back out into the barren fields. "
        );
SetItems( ([
  ({"room", "hut"}) : 
             (:GetLong:),
  ({"walls", "wall"})  : 
             "The walls are completely bare and mostly rotted "
             "away.",
  ({"ceiling"}) : "The ceiling is completely missing "
             "except for the original wood frame that is mostly "
             "rotted away and drooping down badly.",
  ({"dirt"}) : 
             "Dried up dirt covers almost the entire termite "
             "eaten floor.",
  ({"floor"}) : 
             "The floor has been badly eaten away. It is covered "
             "in dried up dirt.",
  ({"door"}) : 
             "The door is hanging onto the frame by one metal "
             "hinge. ",
  ({"window"}) : 
             "All thets left of the window is its framed box. "
             "The glass has long been gone.",
  ({"hinge"}) : 
             "The hinge is very rusty. It is attached to the "
             "door frame barely holding on the door.",
         ]) );
SetItemAdjectives( ([
          "hut" : ({ "small" }),
          "hinge" : ({ "rusty" }),
          "wall" : ({"rotted", "bare"}),
          "door" : ({ "hanging"}),
          "dirt" : ({"dried", "dried up"}),
          "floor" : ({"termite", "eaten"}),
          "ceiling" : ({"drooping", "decaying"}),
]) );
SetListen( (["default" : "The room sounds as if it is shifting "
                         "back and forth.",
         ]) );
SetSmell( (["default" : "The hut smells of dust and dirt.",
        ]) );
SetInventory( ([ AVB_NPC + "centipede" : 2,
                 AVB_NPC + "crow" : 1
            ]) );
SetExits( (["out" : "field8",]) );
    }
