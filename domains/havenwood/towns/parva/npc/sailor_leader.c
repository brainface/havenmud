#include <lib.h>
#include "../parva.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Parva");
  SetLimit(1);
  SetRace("human");
  SetGender("male");
  SetClass("sailor");
  SetMorality(-100);
  SetLevel(20);
  SetKeyName("Bootstrap Bill");
  SetId( ({ "bill", "bootstrap", "sailor", "pirate" }) );
  SetShort("Bootstrap Bill the Sailor");
  SetLong(
    "Bootstrap Bill is a wiry young man. His stories of the sea regale "
    "the young of the town, and some even elect to take up the life of "
    "the sea."
    );
  SetAction(1, ({
    "!emote hums a little ditty.",
    "!emote wobbles a bit.",
    "!emote sings a happy tune.",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Swabby",
    "mortal" : "the Sailor",
    "hm"     : "Captain $N",
    "legend" : "Captain $N the Legendary Sea Dog",
    "avatar" : "Captain $N the Salt of the Sea",
    ]) );
  SetCurrency("oros", 30 + random(30) );
  SetInventory( ([
    STD_WEAPON + "slash/longsword" : "wield longsword",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "slash/longsword" : 1,
    ]) );
}
