#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-2,1,-2);

  SetLong("Dark and foreboding, the tunnel leads off to the east. The "
     "dark stone that makes up the tunnel walls is covered with muck and "
     "slime. Small torches stretch the tunnels walls, few and far between, "
     "giving just enough flickering light to see on to the next passage.");
  SetItems( ([
     ({"wall","walls"}) : "The walls of the tunnel are made from a dark "
       "heavy stone, and they curve towards the center. They are as "
       "filthy as the floor, covered in muck and slime from the sewers.",
     ({"stone","stones"}) : "These dark stones make up all the sewer "
       "tunnels. They are smeared with muck and slime from the streams "
       "of refuse that run through the tunnels above.",
     ({"muck","slime"}) : "This foul smelling muck covers the floor and "
       "walls of the tunnel. Dark and thick looking it clings to everything "
       "that touches it.",
     ({"torch","torches"}) : "These small wooden torches hang from the "
       "walls randomly, and give off enough light for a dim veiw of the "
       "passages ahead.",
     ]) );
  SetItemAdjectives( ([
     "wall" : ({"curved"}),
     "stone" : ({"dark","large"}),
     "torch" : ({"small","wooden"}),
     ]) );
  SetInventory( ([
     AVERATH_NPC "hbeggar" : 1,
     ]) );
  RemoveExit("west");
  RemoveExit("north");
  RemoveExit("south");
   SetAmbientLight(26);
}
