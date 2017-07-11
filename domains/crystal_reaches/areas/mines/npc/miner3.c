/*    /realms/haun/areas/mines/npc/miner3.c
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
    SetAdjectives( ({"large"}) );
    SetShort("a large miner");
    SetLong("This miner seems to have a husky look about him.  He is large"
      " and burly halfling, which gives him the appearance of being a very"
      " powerful worker.");
    
    SetRace("halfling");
    SetClass("fighter");
    SetSkill("mining",1,2);
    SetLevel(11);
    SetCurrency("nuggets", 5);
    SetGender("male");
    SetInventory( ([
			M1_OBJ + "/shirt3.c" : "wear vest",
			M1_OBJ + "/pant3.c" : "wear breeches",
			M1_OBJ + "/pick.c" : "wield pick",
			M1_OBJ + "/boot1.c" : "wear boots",
      ]) ); 
    SetMorality(300);
    SetAction(6, ({ 
    	"A miner picks away at the wall of the cave.",
    	"!mine with pick",
    	}));
}
