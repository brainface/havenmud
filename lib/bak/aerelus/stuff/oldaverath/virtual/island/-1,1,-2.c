#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-1,1,-2);

  SetLong("Dark and foreboding, the tunnel continues to the south and "
     "west. The curved walls of the tunnel are wet and slimy, and the "
     "ceiling is high enough in the center to allow a human of average "
     "height to stand upright. A small grate opens from the ceiling to "
     "the tunnels above. Created from large dark stones, the tunnel can "
     "give even the most fearless an occasional feeling of  claustrophobia. "
     "A small door lies on the north wall of the tunnel and is covered "
     "in muck and dirt just the the floor and walls.");
  SetItems( ([
     ({"wall","walls"}) : "The walls of the tunnel are made from a dark "
       "heavy stone, and they curve towards the center. They are as "
       "filthy as the floor, covered in muck and slime from the sewers. "
       "A small squat door can be seen on the northern wall.",
     ({"grate"}) : "A small stream of muck and waste fall from the metal "
       "grate overhead, you could probably squeeze through it to get to "
       "the sewer tunnels above.",
     ({"ceiling"}) : "The ceiling is nearly tall enough in the center "
       "for an average human to stand upright. A small metal grate is "
       "loosened directly overhead.",
     ({"stone","stones"}) : "These dark stones make up all the sewer "
       "tunnels. They are smeared with muck and slime from the streams "
       "of refuse that run through the tunnels above.",
     ({"floor"}) : "The stone floor has a puddle of green water and "
       "waste that falls in from the grate.",
     ({"door"}) : "The door looks heavy and old, the words 'Maintenance' "
       "can barely be made out on it.",
     ]) );
  SetItemAdjectives( ([
     "wall" : ({"curved","stone"}),
     "door" : ({"small","squat","old","heavy"}),
     "grate" : ({"small","metal"}),
     "stone" : ({"dark","large"}),
     ]) );
  SetEnters( ([
     "door" : AVERATH_GOBLIN "bhome",
     ]) );
  SetExits( ([
     "up" : AVERATH_UNDERGROUND "-1,1,-1",
     "west" : AVERATH_UNDERGROUND "-2,1,-2",
     "south" : AVERATH_UNDERGROUND "-1,0,-2",
     ]) );
  RemoveExit("north");
  RemoveExit("east");
}
