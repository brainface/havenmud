
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("northeast, southeast");
  SetShort("a turn in the cave");
  SetLong(
          "Along the west wall is a blood stained rack with a tiny "
          "wooden stand next to it with few tools along its top surface. "
          "The walls bend slightly making bending around back into the "
          "tunnels. Dried puddles of blood have previously dripped "
          "into a drain in the floor.");
  SetInventory(([ 
             TOWER_NPC "zombie" : 2,
             TOWER_NPC "skeleton1" : 1, 
             ]));
  SetExits( ([
            "northeast"     : TOWER_ROOMS "cave17",
            "southeast"     : TOWER_ROOMS "cave14",
           ]) );
  SetSmell( ([
            "default" : "Smells of death and dried blood.",
           ]) );
  SetListen( ([
            "default" : "A slight crackling is heard."
           ]) );
  
  SetItems( ([
     "wall"    : "Made of natual rock, it rounds from the floor and "
                 "reaches to the ceiling.",
    "rack"     : "A brutal torture device made of wood, rollers and rope. It "
                 "is drenched in dried blood.",
    "blood"    : "The blood covers the floor by the rack and stand. The "
                 "dried puddles make way into a drain.",
    "stains"   : "Stains are seen on the rack, tools and stand.",
    "tools"    : "Two tools rest on the wooden stand, a rusted saw and "
                 "pliers.",
    "saw"      : "It rests on the table next to the pliers. It is covered "
                 "in dried blood which has rusted the saw through.",
    "pliers"   : "The pliers rest on the table resting in a dried blood "
                 "stain. In the mouth of the pliers is a rotted toe nail.",
    "drain"    : "The drain is just a deep hole filled with dried dirt "
                 "and blood inside.",
    "puddles"  : "Dried blood puddles strew the floor near the stand and "
                 "rack.",
    "ceiling"  : "The ceiling has an uneven flat surface and bends down "
                 "to create the walls.",
    "walls"    : "The walls bend outward giving plenty of room in this "
                 "alcove. A rack and stand rest near the west wall.",
    ({ "ground", "floor" }) : "Covered in dried blood stains the black "
                              "packed clay can still be seen.",
    ({ "stand" }) : "The wooden stand has two tools atop "
                    "its surface. It is covered in dried "
                    "blood stains which make its way to "
                    "the floor. It is made of a dark and "
                    "warped wood.",
	"nail" : "There is some dirt on it.",
              ]) );
    SetItemAdjectives( ([
    "stand" : ({ "wooden" }),
    "puddles" : ({ "dried","blood" }),
    "tools" : ({ "two" }),
    "saw" : ({ "rusted" }),
    "rack" : ({ "torture" }),
    "walls" : ({ "rock" }),
    "wall" : ({ "rock" }),
  ]) );
  }
