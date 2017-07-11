/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("on a shale slide");                                              
  SetLong(
    "This appears to be the end of the forest path. The path "
    "ends at the foot of a shale slide which has crushed all of the "
    "trees at the foot of the mountain."
  );
    SetItems( ([         
    ({ "trees", "crushed trees" }) : "What was once scrub pine and small "
    "hardwoods were crushed into splinters suitable for toothpicks by "
    "the weight of the shale slide.",
    ({ "forest" }) : "The forest which surrounds the city of Jidoor is "
    "lush and full of life.",
    ({ "shale", "shale slide", "slide" }) : "A pile of loose shale "
    "which has slid down the mountain side from somewhere above. It "
    "looks as if one could progress along it and gain access to the "
    "woods further down the path.",
    ({ "path", "forest path" }) : "A worn path through the woods which "
    "resembles an animal track.",
    ({ "mountain" }) : "One of the mountains in the Crystal Reaches "
    "range. A snow cap sits atop the mountains high overhead.",
      ]) );
     SetInventory( ([
        NPC+"mdwarf" : random(2)+2,
        NPC+"fdwarf" : random(2)+2,
      ]) );                                                                  
    SetExits( ([
	"up"      : RMS+"path8",
	"southeast"  : RMS+"path6", 
      ]) );
} 
