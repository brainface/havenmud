#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a dense region");
    SetDomain("Crystal Reaches");
    SetLong("Plants once grew in a great density here, but now "
      "only the dry remains of a thicket remain. It seems as "
      "though something removed all life in the area. Plants "
      "with the remains of fresh sprouts and great vigor are now "
      "dead. Very few small trees grow here, but they too have "
      "nearly rotted away to nothing."
    );
    SetItems( ([
      ({"tree", "trees"})  :  
      "Many small trees once grew here, but are now rotten as is the "
      "rest of the area.",
      ({"vegetation", "forest", "woods", "wood"})  :
      "The forest has been made very sick by an unseen force.  "
      "Most of the trees are slowly dying.", 
      "thicket"  :  (: GetLong :),
      ({"plants", "plant", "brush", "underbrush"})   :
      "The dry shells of a prospering population of plants is all that "
      "remains of a once healthy area.",
    ]) );
    SetItemAdjectives( ([
      "tree"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "vegetation"  :  ({"insane", "diseased", "rotten", "twisted"}),
      "plants"  :  ({"dead", "dry"}),
    ]) );
    SetSmell( ([
      "default"  :  "The scent of decaying plant matter fills the air.",
    ]) );
    SetListen( ([
      "default"  :  "Creatures can be heard rustling in the forest.",
    ]) );
    SetInventory(([
       NPCS + "/littlebeast.c" : 2 
    ]));
   SetExits( ([
     "northeast" : ROOMS + "/sunken.c",
     "south" : ROOMS + "/forest2.c",
     "southwest" : ROOMS + "/forest.c",
    ]) );
}
