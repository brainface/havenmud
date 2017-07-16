/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"                                                            
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("the mountain path");                                              
    SetLong("This is path up the side of a mountain. The terrain around "+      
      "the path is rugged but will support some of the hardier plant life. "+
      "To the sides of the path are various shrubs and grasses growing in "+
      "small clumps. Just to the east are five somewhat small huts "+
      "clustered together.");                                          
    SetItems( ([                                                                
	({ "path" }) : "A worn path on the edge of the mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
	({ "structures","huts","small structures","structure","small structure",
	  "hut" }) : "There's a group of five stone huts just down "+
	"the path.",
	({ "shrub", "shrubs" }) : "The shrubs are small and grow close to the "+
	"ground. Each branch has a lot of small, flat, thick leaves which "+    
	"appear very durable.",                                                 
	({ "grass", "grasses" }): "The grasses grow in clumps wherever "+ 
	"they can find purchase in the rocky soil. Enough of the grasses "+     
	"put together would form a nice mattress.",                             

      ]) );                                                                     
    SetClimate("arid");   
    SetExits( ([                                                                
	"up" : RMS+"mpath9",                                             
	"southeast" : RMS+"mpath11",                                             
      ]) );                                                                     
    SetSmell( ([
	"default" : "The smoke coming from the huts lightly scents the wind.",
      ]) );
    SetInventory( ([
        NPC+"mdwarf" : random(2)+2,
        NPC+"fdwarf" : random(2)+2,
      ]) );
  SetDomain("Valley");
}
