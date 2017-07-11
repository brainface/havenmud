/*crew1
 Zara 8/8/98
*/

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include "../acove.h"
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("pirate");
  SetShort("an undead pirate");
  SetId( ({"crew","member"}) );
  SetAdjectives( ({"undead","poised","crew"}) );
  SetLong("This crew member is poised to fight. A sword is "
         "tucked into the sash at his waist.");
  SetGender("male");
  SetMorality(-1000);
  SetRace("human");
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("cavalier");
  SetLevel(25);
  SetAction(5,
        ({"!emote dodges back and forth brandishing his sword."})
        );
  SetInventory( ([
       ACOVE_OBJ + "longsword" : "wield longsword",
        ]) );
}

int eventDie(object killer) {
  object pirate_inv;
  if(!random(200)) {
     pirate_inv = new(DIR_INVASIONS + "/haven_pirate/pih_inv");
    INVASION_D->eventRegisterInvasion(pirate_inv, killer);
  }
  return ::eventDie(killer);
}
