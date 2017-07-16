/*    /realms/haun/areas/mines/npc/miner2.c
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
    SetAdjectives( ({"small"}) );
    SetShort("a small miner");
    SetLong("Covered with a mixture of water and dirt, this miner is"
      " slowly shoveling away at the side of the cave.  This miner is very"
      "small, but he seems to have a bit of power in him.");            

    
    SetRace("halfling");
    SetClass("fighter");
    SetSkill("mining",1,1);
    SetLevel(8);
    SetCurrency("nuggets", 3);
    SetGender("male");
    SetInventory( ([
			M1_OBJ + "/shirt2.c" : "wear shirt",
			M1_OBJ + "/pant2.c" : "wear pants",
			M1_OBJ + "/shovel.c" : "wield shovel",
			M1_OBJ + "/boot2.c" : "wear boots",
      ]) ); 
    SetMorality(300);
    SetAction(6, ({ 
    	"A miner shovels dirt from the wall of the cave.",
    	"!mine with shovel",
    	}));
}
