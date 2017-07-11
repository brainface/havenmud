#include <lib.h>
#include "../path.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("raspy");
  SetShort("Raspy the Healer of the Shire");
  SetId( ({ "healer", "raspy" }) );
  SetAdjectives( ({ "shire" }) );
  SetRace("halfling");
  SetGender("male");
  SetClass("priest");
  SetLevel(20);
  SetCurrency( ([
    "rounds" : 100,
    ]) );
  SetMorality(2000);
  SetFees( ([
    "resurrect" : 1,
    "stamina"   : 1,
    "health"    : 1,
    "restore"   : 1,
    ]) );
  SetLong("Raspy the Healer of the Shire performs his services "
          "for a nominal fee.  His desires to do nothing more "
          "than heal the sick are the core of his being. If you "
          "are wounded or undead, Raspy can help.");
  SetTown("Lloryk");
  SetReligion("Eclat");
  SetAction(3, ({
    "!emote hums a little tune.",
    "!speak Ask me to help you.",
    "!speak From each according to his means...",
    "!speak ...To each according to his needs.",
    }) );
  SetLocalCurrency("rounds");
}

int eventHeal(object who, string what) {
  if (who->GetRace() != "halfling") {
    eventForce("speak I only help halflings.");
    return 1;
    }
  return ::eventHeal(who, what);
}