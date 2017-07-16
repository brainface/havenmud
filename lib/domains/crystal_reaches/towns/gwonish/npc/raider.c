#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../gwonish.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("lizardman raider");
  SetId( ({ "raider", "lizardman", "gwonish_npc", }) );
  SetShort("a lizardman raider");
  SetLong(
    "This lizardman seems intent on sacking the Shire and "
    "carrying away its riches. His demeanor is one of plunder "
    "and murder."
    );
 
  SetLimit(6);
  SetRace("lizardman");
  SetClass("fighter");
  SetSkill("pierce combat",1,1);
  SetLevel(15);
  SetGender("male");
  SetFriends( ({ "chieftan" }) );
  SetCurrency("rounds", 100);
  SetMorality(-200);
  SetAction(10, ({ 
  }) );
  SetCombatAction(5, ({
  }) );
  SetWanderSpeed(2);
  SetInventory( ([
    GWONISH_OBJ "spear" : "wield spear",
    ]) );
}

int eventDie(object killer) {
  object lizard_inv;
  if(!random(100)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
