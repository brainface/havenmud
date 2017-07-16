/* A lizardman healer */
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../gwonish.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetRace("lizardman");
  SetTown("Gwonish");
  SetFees( ([
    "resurrect" : 5,
    "stamina"   : 1,
    "health"    : 3,
    "magic"     : 10,
    "restore"   : 1,
    ]) );
  SetLocalCurrency("rounds");
  SetGender("male");
  SetKeyName("sathis");
  SetShort("Sathis of Gwonish, a tribal healer");
  SetLimit(1);
  SetId( ({ "sathis", "healer" }) );
  SetAdjectives( ({ "gwonish", "tribal" }) );
  SetLong(
    "Sathis of Gwonish is the local healer. He can restore "
    "limbs lost or even bring the dead back to life. His demeanor "
    "is one of severe interest in the world."
    );
  SetReligion("Kuthar");
  SetClass("shaman");
  SetLevel(30);
  SetInventory( ([
    ]) );
  SetMorality(-350);
}
int eventDie(object killer) {
  object lizard_inv;
  if(!random(75)) {
    lizard_inv = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizard_inv, killer);
  }
return ::eventDie(killer);
}
