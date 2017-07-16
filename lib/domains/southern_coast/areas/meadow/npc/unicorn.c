
/* meadow unicorn
  kyla 10-25-97
*/
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../meadow.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("unicorn");
  SetId( ({
         "unicorn",
          }) );
  SetAdjectives( ({
        "mystical", "beautiful",
            }) );
  SetShort("a mystical and beautiful unicorn");
  SetRace("unicorn");
  SetClass("animal");
  SetLevel(50);
  SetMorality(3000);
  SetGender("female");
  SetAction(5,({
          "The unicorn looks at you with sad eyes."
             }) );
  SetLong("This beautiful and mystical unicorn radiates a kind of magic and "
           "appears to be quite sad. Her horn is quite beautiful and seems "
            "to give off a faint glow.");
  }

int eventDie(object agent) {
  object horn;
  object demon_inv;
  if(!random(500)) {
    demon_inv = new(DIR_INVASIONS + "/haven_demon/dih_inv");
    INVASION_D->eventRegisterInvasion(demon_inv, agent);
  }

  horn = new(MEADOW_OBJ + "horn");
  horn->eventMove(this_object());
  return (npc::eventDie(agent));
  }
