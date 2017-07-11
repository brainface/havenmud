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
  SetClass("sailor");
  SetLevel(20);
  SetMorality(100);
  SetKeyName("Hippalus");
  SetId( ({ "hippalus", "sailor" }) );
  SetShort("Hippalus the Sailor");
  SetLong(
    "Hippalus is an old well built man. Though he now spends most of his time "
    "on land, it is clear from the way he stands that he has spent most of his "
    "life at sea. If asked he would be happy to share his knowledge."
    );
  SetAction(1, ({
    "!say Be a Sailor! Sail the seas!",
    "!say Buy me a drink and maybe I'll tell you a story.",
    "!emote wobbles a bit.",
    "!burp",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Cabin Boy",
    "mortal" : "Matey $N the Deckhand",
    "hm"     : "the Argonaut",
    "legend" : "the Odyssean",
    "avatar" : "the Ravager of the Ruined Sea",
    "bard"   : "the Siren of Sanctum",
    "rogue"  : "the Coastal Terror",
    "fighter": "the Legio of the Ruined Sea",
    ]) );
  SetCurrency("imperials", 10 + random(500) );
  SetInventory( ([
    STD_WEAPON + "slash/longsword" : "wield longsword",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "knife/freeknife" : 1,
    ]) );
}
