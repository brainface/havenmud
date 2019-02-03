// Torak@haven 2019
// dalnairn recode 2014-2019 (jesus this is taking forever)

#include <lib.h>
#include <std.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("rus");  
  SetId( ({ "rus", "dalnairn_people", "drowned", "the drowned" }) );
  SetShort("Rus the Drowned");  
  SetLong(
    "Rus, solemn priest of the drowned god, "
    "watches the bay with cold knowing eyes. "
    "His hair is perpetually damp. ",
  );
  SetFriends("dalnairn_people");  
  SetRace("human");
  SetGender("male");
  SetClass("priest");
  SetLevel(70);
  SetUnique(1);
  SetReligion("Damhair");
  SetMorality(0);
  SetCurrency("shards", random(400)+400);
  SetAction(4, ({
//    "!emote eyes you over.",
  }) );
  SetCombatAction(5, ({
    "!disorient",
  }) );
  SetTown("Dalnairn");
  SetPlayerTitles( ([ 
// literally the same titles as the parvan damhair priest//
// i like them //
    "newbie"  : "the Newly Drowned",
    "mortal"  : "the Bringer of Tides",
    "hm"      : "the Rider of the Waves",
    "legend"  : "the Storm of the Seas",
    "avatar"  : "Grand Storm $N the Thundercloud of Damhair",
    "fighter" : "the Breaker of Hulls",
    "rogue"   : "the Stalker of Shores",
  ]) );
  SetFreeEquip( ([
    STD_WEAPON "blunt/war-hammer" : 1,
    ]) );
  SetInventory ( ([
    STD_WEAPON "blunt/war-hammer" : "wield hammer",
    ]) );
  SetSpellBook( ([
    "protective storm" : 100,
    ]) );
  SetAction(5, ({
    "!say the Drowned God protects Parva",
    "!say Join the Order of the Drowned God!",
    }) );
  SetCombatAction(20, ({
    }) );
  SetFirstCommands( ({
    "cast protective storm",
    "cast protective storm",
    "cast protective storm",
    "cast protective storm",
    "cast protective storm",
  }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast protective storm");
  }
}
