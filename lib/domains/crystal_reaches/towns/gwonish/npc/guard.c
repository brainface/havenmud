#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../gwonish.h"
inherit LIB_TOWNGUARD;

int CheckHalfling(object who);

static void create() {
  ::create();
  SetKeyName("lizardman guard");
  SetShort("a greenish-black lizardman guard");
  SetId( ({ "lizardman", "guard", "gwonish_npc" }) );
  SetAdjectives( ({ "greenish", "black", "lizardman" }) );
  SetRace("lizardman");
  SetTown("Gwonish");
  SetClass("rogue");
  SetGender("male");
  SetLevel(25);
  SetMorality(-100);
  SetFriends( ({ "gwonish_npc" }) );
  SetLong("This greenish-black lizardman is one of the defenders of "
          "the village of Gwonish. He looks smug and unhappy, but "
          "completely given to defend the town.");
  
}

int CheckHalfling(object who) {
	if (who->GetRace() == "halfling") {
		eventForce("speak You're not welcome here, halfling!");
		eventForce("growl " + who->GetKeyName());
	  if (!newbiep(who)) return 1;
	}
	return 0;
}
int eventDie(object killer) {
  object lizard_inv;
  if(!random(100)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
