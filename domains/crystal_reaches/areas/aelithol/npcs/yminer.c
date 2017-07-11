#include <lib.h>
#include "../aelithol.h"
inherit LIB_NPC;
    static void create() {
    npc::create();
    SetKeyName("miner");
    SetId( ({ "miner", "young miner", "a young miner" }) );
    SetAdjectives( ({"young"}) );
    SetShort("a young miner");
    SetLong("This dirty, sweaty miner hauls gangue stones "
      "from the mine to the gangue piles outside of the "
      "mine.  He lacks the endurance of the older miners "
      "and looks extremely tired.");                
    
    SetRace("human");
    SetClass("fighter");
    SetSkill("melee combat",1,2);
    SetGender("male");
    SetLevel(7);
    SetMorality(150);
    SetInventory( ([
      OBJS + "/breeches" : "wear breeches",
      OBJS + "/pick" : 1,
    ]) );
    SetAction(3, ({ "The miner works on gathering stones." }));
    
}
