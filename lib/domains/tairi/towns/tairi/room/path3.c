#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("along a road in Tairi");
  SetExits( ([
    "southeast" : "path1",
    "northwest" : "cemetery",
    ]) );
  SetLong("This small path leads northwest to the funeral grounds "
          "of Tairi and back southeast to the Tai mountain range. "
          "A small patch of wildflowers lines the roadway here, "
          "making this town seem more pleasant by far.");
  SetItems( ([
     ({ "town", "tairi" }) :
                 "The town of Tairi is off to the northeast.",
       
     "grounds" : "The funeral grounds lie to the northwest.",
     ({ "flower", "flowers", "wildflower", "wildflowers", "patch" }) :
                 "The wildflowers grow quite peacefully by "
                 "side of the path.",
     ({ "path", "road", "roadway" }) : 
     	           "This small path leads to the funeral grounds in "
     						 "the northwest and to the checkpoint in the south"
     						 "east.",
     ({ "range","mountain", "mountains", "ranges" }) :
     						 "The Tai mountain range surrounds this small valley "
     						 "making it feel secure from outside forces.",
     "checkpoint" : "The checkpoint is off towards the southeast."
     ]) );
  SetItemAdjectives( ([
    "patch"   : "small",
    "flower"  : "wild",
    "grounds" : "funeral",
    "path"    : "small", 
    "range"   : ({ "tai", "mountain" }),
    ]) );
  SetSmell( ([
    "default" : "The scent of flowers drifts through the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of town life fill the area.",
    ]) );
}

