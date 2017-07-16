#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arctic");
  SetShort("near a lodge");
  SetDayLong(
     "Dead trees line this small pathway through the forest, bare "
     "of any leaves, the twisted and blackened branches reach out in "
     "all directions like giant claws. The ground is covered in a thick "
     "layer of dismal gray snow, lifeless bushes piercing through it. "
     "A lodge sits to the north, smoke billowing from its chimney. "
     "Prints in the snow are those of animals seeking shelter and fresh "
     "pairs of large footprints. Light spilling though the arms of the "
     "trees and reflecting off the snow is more than enough to brighten "
     "the area. The pathway continues north and south."
     );
  SetNightLong("Dead trees line this small pathway through the forest, "
     "bare of any leaves, the twisted and blackened branches reach out in "
     "all directions like giant claws. The ground is covered in a thick "
     "layer of dismal gray snow, lifeless bushes piercing through it. A "
     "lodge sits to the north, smoke billowing from its chimney. Prints "
     "in the snow are those of animals seeking shelter and fresh pairs of "
     "large footprints. Moonlight spilling though the arms of the trees and "
     "reflecting off the snow is more than enough to illuminate the passage. "
     "The pathway continues north and south.");
  SetSmell( ([
     "default" : "The scent of burning wood lingers here.",
     ]) );
  SetListen( ([
     "default" : "The soft crunching of walking on snow fills the air.",
     ]) );
  SetItems( ([
     "forest" : "Dense and primarily dead trees fill the forest, branches "
       "outstretched like flailing limbs. The further inward through the "
       "trees, the darker the shadows become.",
     ({"tree","trees"}) : "Like huge twisted monsters, dead and half charred, "
       "these trees stand, almost as a warning to turn back. Light spills"
       "through the bare branches, lighting them with a grayish glow.",
     ({"bush","bushes"}) : "Once probably vibrant green bushes, they now  "
       "lay dead under mounds of snow, fighting to push through.",
     ({"print","prints","footprint","footprints"}) : "Small prints are left "
       "behind obviously made by small animals, they lead from bush to bush. "
       "And larger pairs of footprints hint at someone close by.",
     ({"snow"}) : "The snow is mostly a dull gray, as though covered in a "
       "fine layer of soot. Small prints dot the otherwise smooth surface.",
     ({"path","pathway","passage"}) : "This pathway seems narrow and rarely "
       "used, though footprints go winding off further into the forest.",
     "ground" : "The ground is covered with a thick layer of gray snow.",
     (("branch","branches")) : "Like skeletal claws, branches seem to twist "
       "out of the trees, completely barren of leaves.",
     "smoke" : "A thin stream of smoke can be seen rising from a distant structure.",
     ({"structure","building","lodge"}) : "Not far off sits a small stone "
       "lodge, a stream of smoke rising from the chimney.",
     "chimney" : "A small brick stack can be seen on the roof of the lodge, "
       "with an outpouring of smoke from it.",      
     ]) );
  SetItemAdjectives(( [
     "tree" : ({"dead","huge"}),
     "bush" : ({"dead","lifeless"}),
     "snow" : ({"gray"}),
     "print" : ({"small"}),
     "lodge" : ({"stone"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "north" : L_ROOM + "outside20.c",
     "south" : L_ROOM + "outside15.c",
     ]) );  
  
 
}
