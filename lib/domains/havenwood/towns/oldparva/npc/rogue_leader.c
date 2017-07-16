#include <lib.h>
#include "../parva.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Parva");
  SetLimit(1);
  SetRace("human");
  SetGender("female");
  SetClass("rogue");
  SetLevel(50);
  SetKeyName("alyce");
  SetId( ({ "alyce" }) );
  SetShort("Alyce the Quick");
  SetLong(
    "Alyce the Quick has a reputation of being quite liberal with "
    "other possessions.  Even in a town famed for its lawlessness, "
    "she ranks as a leader among rogues."
    );
  SetAction(1, ({
    "!emote stares around confidently.",
    "!emote eyes your purse.",
    "!emote ponders your situtation.",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Nimble",
    "mortal" : "the Dodgy",
    "hm"     : "the Swift",
    "legend" : "the Quick",
    "avatar" : "the Cutpurse",
    ]) );
  SetCurrency("oros", 3000 + random(3000) );
  SetInventory( ([
    STD_WEAPON + "knife/stiletto" : "wield stiletto",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "knife/freeknife" : 2,
    DIR_STD    "lockpicks/newbiepicks" : 1,
    ]) );
}
