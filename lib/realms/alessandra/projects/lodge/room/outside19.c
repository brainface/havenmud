#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arctic");
  SetShort("outside a stone lodge");
  SetDayLong(
     "Dead trees line this small pathway through the forest, bare "
     "of any leaves, the twisted and blackened branches reach out "
     "in all directions like giant claws. The ground is covered in "
     "a thick layer of dismal gray snow, lifeless bushes piercing "
     "through it. A lodge entrance is here and there is smoke billowing "
     "from its top. Light spilling though the arms of the trees and "
     "reflecting off the snow is more than enough to brighten the area. "
     "Prints in the snow are those of animals seeking shelter and a "
     "fresh pair of large footprints. The pathway curves around the "
     "lodge."
     );
   SetNightLong("Dead trees line this small pathway through the forest, "
     "bare of any leaves, the twisted and blackened branches reach out in "
     "all directions like giant claws. The ground is covered in a thick "
     "layer of dismal gray snow, lifeless bushes piercing through it. A "
     "lodge entrance is here and there is smoke billowing from its top. "
     "Moonlight spilling though the arms of the trees and reflecting off "
     "the snow is more than enough to illuminate the passage. Prints in the "
     "snow are those of animals seeking shelter and a fresh pair of large "
     "footprints. The pathway curves around the lodge.");
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
       "used, though footprint lead around the outside of the lodge.",
     "ground" : "The ground is covered with a thick layer of gray snow.",
     (("branch","branches")) : "Like skeletal claws, branches seem to twist "
       "out of the trees, completely barren of leaves.",
     "smoke" : "A stream of smoke billows from the top of the lodge.",
     ({"structure","building","lodge"}) : "A stone lodge sits here. It looks "
       "warm and inviting inside. There is an entrance here.",
     ]) );
  SetItemAdjectives(( [
     "tree" : ({"dead","huge"}),
     "bush" : ({"dead","lifeless"}),
     "snow" : ({"gray"}),
     "print" : ({"small"}),
     "lodge" : ({"stone"}),
     ]) );
  SetInventory( ([
     L_NPC + "protector" : 1,
     ]) );
  SetExits( ([
     "east" : L_ROOM + "outside14.c",
     "northwest" : L_ROOM + "outside18.c",
     "southwest" : L_ROOM + "outside20.c",
     ]) );
  SetEnters( ([
     "lodge" : L_ROOM + "mainfloor.c",
     ]) ); 
}
