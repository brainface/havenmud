#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(0,0,-2);
  SetLong("Created from large stones, the tunnel walls are curved and "
     "hold small torches randomly to light the passage. On the floor runs "
     "a small trickle of the sewage from the tunnels above and the walls "
     "are wet and slimy. The passage continues to the east and west.");
  SetItems( ([
     ({"stone","stones"}) : "These dark stones make up all the sewer "
       "tunnels. They are smeared with muck and slime from the streams "
       "of refuse that run through the tunnels above.",
     ({"floor"}) : "The stone floor carries a trickle of green water and "
       "waste that runs through the tunnels above.",
     ({"wall","walls"}) : "The walls of the tunnel are made from a dark "
       "heavy stone, and they curve towards the center. They are as "
       "filthy as the floor, covered in muck and slime from the sewers. ",
     ({"torch","torches"}) : "These small wooden torches are spaced few "
       "and far between across the tunnel walls. They barely manage to "
       "keep the passages lit.",
     ]) );
  SetItemAdjectives( ([
     "stone" : ({"dark","large"}),
     "floor" : ({"stone"}),
     "wall" : ({"curved","stone"}),
     "torch" : ({"small","wooden"}),
     ]) );
  RemoveExit("north");
  RemoveExit("south");
   SetAmbientLight(26);
}
