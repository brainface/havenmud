// Torak@haven 2019
// dalnairn recode 2014-2019 (jesus this is taking forever)

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("trost");  
  SetId( ({ "trost", "", "dalnairn_people" }) );
  SetShort("Trost");  
  SetLong(
    "Trost is a keen eyed dark-dwarf. "
    "He is well groomed and takes pride in his appearance. "
    "His thick black beard is braided and tied with "
    "colorful bows at the tips. "
  );
  SetFriends("dalnairn_people");  
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(40);
  SetUnique(1);
  SetReligion("Damhair");
  SetMorality(-300);
  SetCurrency("shards", random(400)+10);
  SetAction(3, ({
    "!emote 's ears twitch.",
    "!emote smiles at you warmly.",
    "!emote jiggles his coin purse.",
  }) );
  SetCombatAction(5, ({
    "!disorient",
  }) );
  SetInventory( ([
    DAL_OBJ + "pants": "wear pants",
    DAL_OBJ + "shirt" : "wear shirt",
    DAL_OBJ + "shoes" : "wear shoes",
    DAL_OBJ + "knife" : "wield knife",
  ]) );
  SetTown("Dalnairn");
  SetFreeEquip( ([
    "/std/weapon/knife/freeknife" : 1,
  ]) );  
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Clerk",
    "mortal" : "the Clerk",
    "hm"     : "the Bookkeeper",
    "legend" : "the Finance Agent",
    "avatar" : "the Auditor",
    "deity"  : "the Patron",
    "rogue"  : "the Mercantile Mariner",
  ]) );
}
