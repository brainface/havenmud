#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../parva.h"

inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Fansy");
  SetProperty("parvanoleave", 1);
  SetRace("human");
  SetClass("bard");
  SetLevel(60);
  SetGender("male");
  SetShort("Fansy the Famous Bard");
  SetId( ({ "fansy", "bard", }) );
  SetLong(
    "Fansy is a famous bard. His music is known throughout the lands of the Havenwood. "
    "Though his musical skills aren't well respected in the Elven lands to the south, they "
    "have a certain charm that is often remarked upon as far north as Gurov. For those seeking "
    "a career in music, Fansy is definitely someone that needs to be spoken with."
    );
  SetAction(5, ({
    "!speak Those seeking to know the songs of the sea should talk with me!",
    "!emote hums a gentle tune.",
    }) );
  SetCombatAction(25, ({
    "!cast aural shield",
    "!cast wail of the banshee",
  }) );
  SetTown("Parva");
  SetMorality(0);
  SetPlayerTitles( ([
    "newbie" : "the Young Musician",
    "mortal" : "the Parvan Lute",
    "hm"     : "the Inciter of Bar Brawls",
    "legend" : "the Bane of the Baths",
    "avatar" : "the Tavern Keeper's Friend",
    "sailor" : "the Face that Launched a Hundred Rumrunners",
    ]) );
  SetFreeEquip( ([
     STD_KNIFE "freeknife" : 2,
     STD_INSTRUMENTS "mandolin" : 1,
     ]) );
  SetInventory( ([
     STD_INSTRUMENTS "mandolin" : "wield mandolin",
     ]) );
  SetCurrency("oros", 50000);
  SetWander(0);
  SetLimit(1);
}
