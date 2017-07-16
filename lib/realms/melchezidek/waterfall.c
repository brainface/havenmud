// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
//  Urien@Haven 12.7.12
//  Brand new Room

#include <lib.h> 
//#include "../castle.h"          

//#define WESTWOOD "/domains/westwood/virtual/westwood/"       
#define RUINS_ROOMS "/realms/urien/ruins/room/"

inherit LIB_FISHING;        
 
static void create() 
{
::create();

SetShort("a waterfall clearing");
SetLong("The pond that rests in the forest ground is made by a waterfall "
        "which has broken through a rock formation to the north. The pond "
		"collects the water from the waterfall and turns the water to "
		"ease, slightly pushing against the shortline. The ruined moat "
		"is off to the east which protects an ancient looking structure. "
		"The varied trees of the Westwood continue to the west. "
		"leading deeper into the forest.");
//SetListen("default","The splash from the waterfall is abuntantly clear.");
//SetSmell("default","Cool, fresh water dominates the air.");
//SetExits( ([
//        "west"      : WESTWOOD + "24,30",
//        "southwest"  : WESTWOOD + "24,29",
//        "south"     : RUINS_ROOMS + "drawbridge",

//        ]) );
// SetEnters( ([
//    "waterfall" : RUINS_ROOMS + "cave1",
//          ]) );
SetClimate("temperate");
SetItems( ([ 
 //   ({ "","" }) : (: GetLong :),

     "waterfall" : "A gushing waterfall rushes from the top of a "
	               "plateau to the small pond below.",
   
    ]) );
SetExits( ([
	"south" : "/realms/melchezidek/workroom",
]) );
/*SetItemAdjectives( ([
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
  ]) );
*/
/* Fishing stuffs*/
//SetChance(50);
//SetMaxFishing(15);
//SetSpeed(8);
//SetFish( ([
//         RUINS_OBJ "muddling" : 100,
 //        RUINS_OBJ "malling" : 30,
 //    ]) );
}
