#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../path.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("lizardman shaman");
  SetShort("an ancient lizardman");
  SetLong("Much smaller than many of its species, this reptile still "
          "presents an aura of danger.  Its eyes are milky from age "
          "and its muscle tone has deteriorated so much that its "
          "scaly skin sags off its bone.");
  SetId( ({"shaman","lizardman shaman","lizardman","lizard","reptile"}) );
  SetRace("lizardman");
  SetClass("shaman");
  SetLevel(random(8)+5);
  SetMorality(-650);
  SetAction(1, ({
       "The ancient lizardman worships at the altar.",
      }) );
  SetGender("male");
  SetSpellBook( ([
     "ice ball" : 60,
     "missile"  : 80,
     "buffer"   : 80,
     ]) );
  SetInventory( ([ GWONISH + "obj/robe" : "wear robe" ]) );
  SetCombatAction(20,({
     "!cast ice ball",
     "!cast missile",
     "!cast buffer",
		}) );
 }

int eventDie(object killer) {
  object lizard_inv;
  if(!random(200)) {
    lizard_inv = new(DIR_INVASIONS + "/jidoor_lizardmen/lmij_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}

