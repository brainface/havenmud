/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("on a shale slide");                                              
    SetLong("This is a slide of shale rock from higher up the mountain. "+
      "No vegetation grows here because of the destructive force of the "+
      "rocks falling down the mountain. It looks as if you can climb "+
      "either further up the mountain or back down to the forest.");                                          
    SetItems( ([         
	({"forest" }) : "The forest which surrounds the city of Jidoor is "+
	"lush and full of life.",
	({ "shale", "shale slide", "slide" }) : "A pile of loose shale "+
	"which has slid down the mountainside from somewhere above. It "+
	"looks as if one could climb it and gain access to the woods "+
	"below.",                                                       
	({ "path" }) : "A worn path up the side of a mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
      ]) );                                                                     
    SetExits( ([
	"up" : RMS+"mpath16",
	"down" : RMS+"path7",
      ]) );
    SetListen( ([
	"default" : "Every step you take makes the shale clink together. "+
	"If there was anyone around they'd certainly know where you are "+
	"by now!",
      ]) );
  SetDomain("Valley");
    SetInventory( ([
        NPC+"mdwarf" : random(2) + 2,
        NPC+"fdwarf" : random(2) + 2,
      ]) );
SetClimate("arid");
}

