#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arctic");
  SetShort("a narrow pathway through the forest");
  SetDayLong(
     "Dead trees line this small pathway through the forest, bare "
     "of any leaves, the twisted and blackened branches reach out in "
     "all directions like giant claws. The ground is covered in a dismal "
     "gray snow, lifeless bushes piercing through it. The small pathway "
     "looks as though it is not traveled frequently. Prints in the snow "
     "are those of animals seeking shelter and a fresh pair of large "
     "footprints. Light spilling though the arms of the trees and "
     "reflecting off the snow is more than enough to brighten the area. "
     "The snow is quite deep here, but the pathway is still noticable to "
     "the east and west."
     );
  SetNightLong("Dead trees line this small pathway through the forest, "
     "bare of any leaves, the twisted and blackened branches reach out in "
     "all directions like giant claws. The ground is covered in a dismal "
     "gray snow, lifeless bushes piercing through it. The small pathway "
     "looks as though it is not traveled frequently. Prints in the snow "
     "are those of animals seeking shelter and a fresh pair of large "
     "footprints. Moonlight spilling though the arms of the trees and "
     "reflecting off the snow is more than enough to illuminate the passage. "
     "The snow is quite deep here, but the pathway is still noticable to "
     "the east and west.");
  SetSmell( ([
     "default" : "The air is filled with the scent of charred wood.",
     ]) );
  SetListen( ([
     "default" : "Whirling winds and the hungry howls of animals echo through the forest.",
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
       "A larger pair of footprints hints at someone close by.",
     ({"snow"}) : "The snow is mostly a dull gray, as though covered in a "
       "fine layer of soot. Small prints dot the otherwise smooth surface.",
     ({"path","pathway","passage"}) : "This pathway seems narrow and rarely "
       "used, though footprints go winding off into the forest.",
     "ground" : "The ground is covered with a thick layer of gray snow.",
     (("branch","branches")) : "Like skeletal claws, branches seem to twist "
       "out of the trees, completely barren of leaves.",
     ]) );
  SetItemAdjectives(( [
     "tree" : ({"dead","huge"}),
     "bush" : ({"dead","lifeless"}),
     "snow" : ({"gray"}),
     "print" : ({"small"}),
     ]) );
  SetInventory( ([
     L_NPC + "defender" : 1,
     ]) );
  SetExits( ([
     "east" : L_ROOM + "outside5.c",
     "west" : L_ROOM + "outside13.c",
     ]) );
   
}
