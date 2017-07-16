/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("a clearing sheltered by huts");                                              
    SetLong("This is a small clearing or courtyard encircled by the "+
      "five huts which stand here. In the center of the courtyard "+
      "is a large fire pit which is currently cold. The signs of "+
      "habitation abound here including both humanoid and canine "+
      "tracks scattered all around.");                                          
    SetItems( ([                                                                
	({ "path" }) : "A worn path on the edge of the mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
        ({ "structures", "structure", "huts" }) : "There are five huts here, "
        "which all look about the same except their colors. There is a "
        "grey, tan, brown, slate and sepia colored hut.",
	({ "pit", "fire", "fire pit", "large pit", "large fire pit" }) :
	"The fire pit is full of ash and charred logs which currently give "+
	"off absolutely no heat.",
	({ "tracks", "humanoid tracks", "canine tracks" }) : "The tracks, "+
	"both human and canine, are unclear because there are so many of "+
	"them which overlap. However, you can discern that the canine "+
	"tracks are those of some large dogs.",                                                                            
	({ "grey hut", "hut" }) : "A small hut very much like the others. "+
	"it is made of stone and wood with a grey hide door.",
	({ "slate hut", "hut" }) : "A small hut very much like the others. "+
	"it is made of stone and wood with a slate hide door.",
	({ "brown hut", "hut" }) : "A small hut very much like the others. "+
	"it is made of stone and wood with a brown hide door.",
	({ "sepia hut", "hut" }) : "A small hut very much like the others. "+
	"it is made of stone and wood with a sepia hide door.",
	({ "tan hut", "hut" }) : "A small hut very much like the others. "+
	"it is made of stone and wood with a tan hide door.",
      ]) );                                                                     
    SetItemAdjectives( ([
      "structures" : ({ "small" }),
    ]) );
    SetClimate("arid");
    SetEnters( ([
	({ "grey hut"   }): RMS+"hut1",
	({ "tan hut"    }): RMS+"hut2",
	({ "brown hut"  }): RMS+"hut3",
	({ "slate hut"  }): RMS+"hut4",
	({ "sepia hut" }): RMS+"hut5"

      ]) );
    SetExits( ([                                                                
	"south" : RMS+"mpath11",                                            
      ]) );                                                                     
    SetInventory( ([
	NPC+"bigdog" : 1,
	NPC+"mdog"   : random(3)+3,
	NPC+"fdog"   : random(4)+3,
      ]) );
    SetSmell( ([
	"default" : "The smoke coming from the huts hangs heavy and smells "+
	"somewhat sweet.",
      ]) );
} 
