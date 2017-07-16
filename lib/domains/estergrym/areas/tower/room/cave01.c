
#include <lib.h>
#include "../defs.h"
#include <domains.h>

#define ESTER_ROAD "/domains/estergrym/virtual/northroad/0,10"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetObviousExits("east");
  SetShort("somewhere aside the north road");
  SetLong(
          "Large boulders that lay scattered about almost hide the "
		  "cave entrance which leads directly into the Estergrym "
		  "Mountains. "
          "Looming above these mountains in the distance is a warped "
          "black tower that views this entire valley. The grass here "
          "has been long dead and is now packed with an exposed black "
          "clay. To the east is the North Road which leads away from "
          "this dreaded scene.");
  SetExits( ([
            "east"      : ESTER_ROAD,
           ]) );
  SetSmell( ([
            "default" : "A strong smell of death eminates from the cave.",
           ]) );
  SetListen( ([
            "default" : "The silence is overwhelming."
           ]) );
  SetItems( ([
      "boulders" : "Some large boulders rest here, they are rather "
	               "massive and look like they have recently fallen "
				   "from the mountains itself",
     ({ "scene" }) : (: GetLong :),
      "boulder"    : "The boulder is orange in color and sphere "
	                 "shaped. It is larger than an average keep.",
     "mountains": "They round off and lead east away from the cave.",
         "road" : "The only road near is the North Road to the east.",
       "valley" : "It is what makes up the North Road",
         "cave" : "It is to the northwest, the entrance is formed by "
                  "rocks. It looks possible to enter the cave.",
        "rocks" : "Black rocks form the entrance to the dark cave.",
        "grass" : "It has a white color to it as if it has been dead "
                  "for some time.",
     "entrance" : "The cave entrance lies to the northwest in darkness.",
         "clay" : "Black clay has been packed to form the rocks and ground.",
        "tower" : "The black tower stands tall over the Estergrym "
	              "Mountains collecting a view of the entire North Road.",
		"road"  : "The North Road lies east.",
              ]) );
  SetItemAdjectives( ([
    "tower"    : ({ "black","warped" }),
    "clay"     : ({ "black","exposed" }),
    "entrance" : ({ "cave" }),
    "mountains": ({ "Estergrym","estergrym"}),
    "grass"    : ({ "dead","white" }),
    "rocks"    : ({ "black" }),
	"road"     : ({ "north" }),
  ]) );
 SetEnters( ([
    "cave" : TOWER_ROOMS "cave02",
           ]) );
  }