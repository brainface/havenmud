/*    /realms/haun/areas/mines/npc/miner4.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h>
#include "../mine1.h"
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("miner");
    SetId( ( "miner" ) );
    SetAdjectives( ({"lonely", "old"}) );
    SetShort("a lonely miner");
    SetLong("This miner is very old, and seems to be crying.  He hammers"
      " violently with the huge hammer that he wields.  He looks to"
      " be in pain.");      

    
    
    SetRace("halfling");
    SetClass("fighter");
    SetSkill("mining",1,2);
    SetLevel(4);
    SetCurrency("nuggets", 1);
    SetGender("male");
    SetInventory( ([
			M1_OBJ + "/shirt4.c" : "wear shirt",
			M1_OBJ + "/pant4.c" : "wear pants",
			M1_OBJ + "/hammer.c" : "wield hammer",
      ]) ); 
    SetMorality(300);
    SetAction(6, ({ 
    	"A miner looks around.",
    	"!mine with hammer",
    	 }));
}
