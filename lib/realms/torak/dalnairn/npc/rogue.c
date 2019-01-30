// Dalnairn
// Aerelus
//
// torak@haven 2019
// edited for dalnairn recode

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("morven");  
  SetId( ({ "morven", "", "dalnairn_people" }) );
  SetShort("Morven");  
  SetLong(
//    "Morven is an evil-looking dark-dwarf. She is very thin and agile, a "
//    "necessity in her profession. Her eyes dart around the area, swiftly "
//    "inspecting people as she judges their financial worth. She is casually "
//    "avoided by most Dark-dwarves, who have a reasonable idea of what she is "
//    "capable of." 
    "Morven is a tall and slender dark-dwarf with piercing blue eyes "
    "sporting a well groomed and thick brown beard. "
    "His long dark red hair is braided into a ponytail. "
  );
  SetFriends("dalnairn_people");  
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("rogue");
  SetLevel(40);
  SetUnique(1);
  SetReligion("Damhair");
  SetMorality(-300);
  SetCurrency("shards", random(400)+10);
  SetAction(3, ({
    "!emote smirks as he looks you over.",
    "!emote throws some food out for the birds.",
    "!emote ignores you completely.",
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
    "newbie" : "the Drifter of Dalnairn",
    "mortal" : "the Recreant Reprobate",
    "hm"     : "the Treacherous Trickster",
    "legend" : "the Mountebank of the Mountain",
    "avatar" : "the Overseer of the Masquerade",
  ]) );
}
