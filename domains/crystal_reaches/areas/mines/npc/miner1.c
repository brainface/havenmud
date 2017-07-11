/*    /realms/haun/areas/mines/npc/miner1.c
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
    SetAdjectives( ({"groaning", "small"}) );
    SetShort("a small miner");
    SetLong("Covered with a mixture of water and dirt, this miner is"
      " slowly picking away at the side of the cave.  This miner is very"
      " small and meek.  He seems to be in pain, and is groaning"
      " under his breath.");             
    
    SetRace("halfling");
    SetClass("fighter");
    SetSkill("mining",1,2);
    SetLevel(11);
    SetCurrency("nuggets", 5);
    SetGender("male");
    SetInventory( ([
			M1_OBJ + "/shirt1.c" : "wear shirt",
			M1_OBJ + "/pant1.c" : "wear pants",
			M1_OBJ + "/pick1.c" : "wield pick",
      ]) ); 
    SetMorality(300);
    SetAction(6, ({ 
    	"The miner picks slowly at the side of the cave.",
    	"!mine with pick",
    	}));
}
