#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;
 static void create() {
  npc::create();
  SetKeyName("female gelfling");
  SetFriends( ({ "gelfling" }) );
  SetId( ({"gelfling"}) );
  SetAdjectives( ({"female"}) );
  SetShort("a female gelfling");
  SetRace("gelfling");
  SetClass("ranger");
  SetSkill("melee combat",1,2);
  SetGender("female");
  SetLevel(10);
  SetLong("This female gelfling appears to be very in tune with her"
         " surroundings and exceptionally aware of her environment.");
  SetMorality(300+random(50));
  SetCurrency("imperials", random(30)+1);
  SetSpellBook( ([
     "condense air" : 100,
     "tangle" : 100,
     "tend wounds" : 100,
     ]) );
  SetCombatAction(50, ({
     "!cast tangle",
     "!cast condense air",
     "!cast tend wounds",
     }) );
  SetInventory( ([
               ]) );
}

int eventDie(object killer) {
  object bandit_inv;
  if(!random(500)) {
    bandit_inv = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandit_inv, killer);
  }
return ::eventDie(killer);
}
