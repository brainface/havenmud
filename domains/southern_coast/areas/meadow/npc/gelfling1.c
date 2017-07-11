#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../meadow.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("male gelfling");
  SetFriends( ({ "gelfling" }) );
  SetId( ({"gelfling"}) );
  SetAdjectives( ({"male"}) );
  SetShort("a male gelfling");
  SetRace("gelfling");
  SetClass("rogue");
  SetLevel(7);
  SetGender("male");
  SetLong("This male gelfling is quite thin but looks as though he would have "
          "no problem defending himself.");
  SetMorality(300 +random(25));
  SetCurrency("imperials", random(50) + 1);
  SetAction(3, ({ 
  	"!glare suspiciously"
  	}) );
  SetCombatAction(10, ({
  	"!disorient",
  	}) );        
  SetInventory( ([
    MEADOW_OBJ + "knife" : "wield knife",
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
