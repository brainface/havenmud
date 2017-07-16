#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;
    static void create() {
    npc::create();
    SetKeyName("miner");
    SetId( ( "miner" ) );
    SetAdjectives( ({"hardworking"}) );
    SetShort("a hardworking miner");
    SetLong("Dust and earth covers the miners skin.  Mixed "
      "with sweat, the filth makes the miner smell rather "
      "badly.  He seems to have once had great strength in "
      "his youth, but the years are taking a toll on him and "
      "he is showing the signs of age.");             
    
    SetRace("human");
    SetClass("fighter");
    SetSkill("mining",1,2);
    SetGender("male");
    SetLevel(15);
    SetMorality(350);
    SetInventory( ([
      OBJS + "/pick" : "wield pick",
      OBJS + "/breeches" : "wear breeches",
      ]) );   
    SetAction(6, ({ 
    	"The miner works at the stone.",
    	"!mine with pick",
    	}) );
    SetFriends( ({"miner", "young miner"}));
}
