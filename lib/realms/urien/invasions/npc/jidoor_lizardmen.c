//Jidoor Lizardmen

#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../invas.h"
#define RIGHT + " in right hand"

inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("lizardman");
  SetId( ({"lizardman","lizard","lizard man","reptile"}) );
  SetShort("a large lizardman");
  SetLong("This green scale covered humanoid is two meters of pure "
          "predator with a bad attitude.");
  
  SetRace("lizardman");
  SetClass("fighter");
  SetSkill("projectile combat",1,2);
  SetLevel(5 + random(5));
  
  if(random(5))
    SetGender("male");
  else
    SetGender("female");
  SetMorality(random(500)-500);
  SetFirstCommands( ({
    "!kill all",
   }) );
}

int eventDie(object killer) {
  object lizard_inv;
  if(!random(1)) {
    lizard_inv = new(DIR_INVASIONS + "/jidoor_lizardmen/lmij_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
