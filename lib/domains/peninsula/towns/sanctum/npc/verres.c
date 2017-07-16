#include <lib.h>
#include "../rome.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Sanctum");
  SetLimit(1);
  SetRace("human");
  SetBaseLanguage("Imperial");
  SetGender("male");
  SetClass("rogue");
  SetLevel(250);
  SetMorality(-1000);
  SetKeyName("Verres");
  SetId( ({ "verres", }) );
  SetShort("Verres the Sly");
  SetLong(
    "Verres the Sly has a reputation of being not only quick and crafty with "
    "his words but with his hands as well. His reputation for liberating funds "
    "ranks him as the leader among rogues."
    );
  SetAction(1, ({
    "!emote stares around confidently.",
    "!emote eyes your purse.",
    "!emote the situation.",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Lightfoot",
    "mortal" : "the Skulker",
    "hm"     : "the Cat Burglar",
    "legend" : "the Shadow of Sanctum",
    "avatar" : "the Faceless Whisper of Sanctum",
    "fighter" : "the Shadow Fighter of the Sanctum Underground",
    "sailor" : "the Scourge of the South Seas",
    ]) );
  SetCurrency("imperials", 500 + random(500) );
  SetInventory( ([
    STD_WEAPON + "knife/stiletto" : "wield stiletto",
    ROME_OBJ "toga" : "wear toga",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "knife/freeknife" : 2,
    DIR_STD    "lockpicks/newbiepicks" : 1,
    ]) );
}
