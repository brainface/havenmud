/*lookout
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
  SetShort("the crow's nest lookout");
  SetId( ({"pirate","lookout"}) );
  SetAdjectives( ({"undead","small"}) );
  SetLong("This pirate's small stature serves him well in "
          "his job as lookout in the crow's next.  His "
          "knife is honed and ready");
  SetGender("male");
  SetMorality(-1000);
  SetRace("human");
  SetUndead(1);
  SetNoCorpse(1);
  SetDie("The pirate crumbles to dust.");
  SetClass("rogue");
  SetLevel(20);
  SetAction(5,
        ({"!emote keeps his watchful eyes on all that goes on "
          "around him at all times."})
        );
  SetInventory( ([
       ACOVE_OBJ + "knife" : "wield knife",
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
