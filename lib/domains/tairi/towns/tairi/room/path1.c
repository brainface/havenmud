/* Entrance path to the city of Tai-Ri
 * 5 May 99
 * Duuktsaryth@Haven
 */
#include <domains.h>
#define WORLD ESTERGRYM_VIRTUAL "northroad/1,40"
#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

int CitizenCheck(string south);

static void create() {
  ::create();
  SetClimate("temperate");
  SetShort("a checkpoint before a town");
  SetInventory( ([
  	TAI_RI_NPC "sam_sentry" : 2,
   ]) );
  SetLong("The path comes to a small checkpoint here before a "
          "small town. To the south, the path leads back towards "
          "the Tai mountain range, while to the north the path "
          "leads directly into Tairi. The mountains lend an over"
          "shadow to a place located pleasantly in a small valley, "
          "giving the appearance of an easy and relaxed life.");
  SetItems( ([
    ({ "town", "tairi" }) :
    	    "The town of Tairi is just north along this dirt road.",  
    ({ "path", "road" }) : 
    	    "The path is a wide dirt road which leads back into the Tai "
    	    "mountain range to the south and into the town to the north.",
    ({ "checkpoint", "access" }) : 
    	    "The checkpoint seems to be a place where guards would be "
    	    "stationed to protect the town.",
    ({ "range", "mountain", "mountains", "valley" }) : 
    	     "The Tai mountain range are an old range and protects this "
    	     "valley from outside forces.",

    ]) );
  SetItemAdjectives( ([
    "path"       : ({ "wide", "dirt" }),
    "range"      : ({ "tai", "mountain" }),
    "checkpoint" : "small",
    "valley"     : ({ "pleasant", "small" }),
    "town"       : ({ "small" , "tairi" }),
    ]) );
  SetExits( ([
    "north"     : "path2",
    "northeast" : "path4",
    "northwest" : "path3",
    ]) );
  AddExit("south", TAIRI_VIRTUAL "tairi_path/0,0", (: CitizenCheck :) );
  SetSmell( ([
    "default" : "The gentle scent of flowers comes from the town.",
    ]) );
  SetListen( ([
    "default" : "The sounds of town life bustle from the north.",
    ]) );
}

int CitizenCheck(string south) {
  if (!userp(this_player()) && (this_player()->GetOwner() == "")) {
      return 0;
   }
  return 1;
}
