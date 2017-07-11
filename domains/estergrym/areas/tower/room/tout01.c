
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetObviousExits("north, southwest, south");
  SetShort("along a mountain base");
  SetLong(
          "The mountains tower up into the sky preventing any "
          "travel out of this deep canyon. The ground outside "
          "is void of all life and barren. A dark black tower "
          "wall can be seen to the west with no special decor "
          "along the outside walls. The skies are visible but "
          "barely penetrate the thick dark fog.");
  SetExits( ([
            "north"      : TOWER_ROOMS "tout02",
            "southwest"  : TOWER_ROOMS "tout03",
            "south"      : TOWER_ROOMS "cave18",   
           ]) );
  SetSmell( ([
            "default" : "A hazy fog wisps around from the mountaintop.",
           ]) );
  SetListen( ([
            "default" : "Silence looms over the barren field."
           ]) );
  SetRadiantLight(25);
  SetItems( ([
     "mountains" : "The Estergrym mountains block off much travel "
                   "due to the sudden steep slopes in them.",
     "mountain"  : "The mountain blocks off any travel up them. It "
                   "reaches around leaving only two passages to "
                   "travel.",
     "wall"      : "The tower wall is made of perfectly cut black "
                    "stone slabs. No windows or openings to the "
                    "tower can be seen.",
     "fog"       : "A black fog looms about dampening the view.",
    ({ "ground", "floor" }) : "The ground is barren and lifeless. "
                               "Packed soil is all that remains from "
                               "the fog blocking out the sunlight.",
    ({ "tower" }) : "The tower is warped and has been "
                    "constructed to be swayed and "
                    "twisted. A black magic hue can "
                    "be seen from just gazing at the "
                    "tower itself.",
	 "stone" : "It is too far from the tower to discern any "
	           "qualities. ",
	 "soil" : "The ground is barren and dead. It is brown in color.",

              ]) );
    SetItemAdjectives( ([
    "tower" : ({ "black","warped" }),
    "wall" : ({ "tower","stone" }),
    "fog" : ({ "black" }),
  ]) );
  }
