/* Create by Aramuuk. 1998 */                                                   
#include <lib.h>                                                                
#include <std.h>                                                                
#include "../path.h"       
                                                     
inherit LIB_ROOM;                                                               

static void create() {                                                          
    room::create();                                                             
    SetShort("the mountain path");                                              
    SetLong("This is path up the side of a mountain. The terrain around "+      
      "the path is fairly barren except a few hardy shrubs and "+               
      "grasses which are growing in scattered clumps. "+                        
      "There are three huts here with doors facing the path.");                                          
    SetItems( ([                                                                
	({ "path" }) : "A worn path on the edge of the mountain.",              
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+     
	"range. The snowcap is far above you.",                                 
	({ "structures","huts","crude structures","structure","crude structure",
	  "hut" }) : "There are three huts here: a large hut, a small hut and "+
	"a round hut. Which do you want to look at?",
	({ "large hut" }) : "This is a large hut with a hide covered door. "+
	"The hut looks "+
	"to be of higher quality than many of the others around here.",                                         
	({ "small hut" }) : "This is small hut with a hide covered door. "+
	"The hut looks big enough to hold about 4 people.",                                         
	({ "round hut" }) : "This is small round hut with a hide covered door. "+
	"The hut has many enigmatic designs painted on it.",                                         
	({ "shrub", "shrubs" }) : "The shrubs are small and grow close to the "+
	"ground. Each branch has a lot of small, flat, thick leaves which "+    
	"appear very durable.",                                                 
	({ "grass", "grasses" }): "The grasses grow in small clumps wherever "+ 
	"they can find purchase in the rocky soil. Enough of the grasses "+     
	"put together would form a nice mattress.",                             

      ]) );                                                                     
    SetClimate("arid");   
    SetExits( ([                                                                
	"northeast" : RMS+"mpath4",                                             
	"southwest" : RMS+"mpath6",                                             
      ]) );                                                                     
    SetSmell( ([ 
	"default" : "The strong smell of different types of smoke hangs in the air.",
      ]) );
    SetEnters( ([                                                            
	({ "large hut", "main hut" }) :  RMS + "chief",
	({ "small hut", "guard hut" }) : RMS + "guard",
	({ "round hut" }) : RMS + "round" 
      ]) );
    SetInventory( ([
        NPC+"guards" : random(3)+2,
      ]) );
  SetDomain("Valley");
}
