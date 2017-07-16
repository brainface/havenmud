// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("morven");  
  SetId( ({ "morven", "devious", "dalnairn_people" }) );
  SetShort("Morven the Devious");  
  SetLong(
    "Morven is an evil-looking Duergar. She is very thin and agile, a "
    "necessity in her profession. Her eyes dart around the area, swiftly "
    "inspecting people as she judges their financial worth. She is casually "
    "avoided by most Duergar, who have a reasonable idea of what she is "
    "capable of."    
  );
  SetFriends("dalnairn_people");  
  SetRace("dwarf");
  SetGender("female");
  SetClass("rogue");
  SetLevel(40);
  SetReligion("Soirin");
  SetMorality(-300);
  SetCurrency("shards", random(100));
  SetAction(5, ({
    "!emote smirks as she looks you over.",
  }) );
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );
  
  SetTown("Dalnairn");
  SetFreeEquip( ([
    "/std/weapon/knife/freeknife" : 1,
  ]) );  
  SetPlayerTitles( ([
    "newbie" : "the Drifter of Dalnairn",
    "mortal" : "the Recreant Reprobate",
    "hm" : "the Treacherous Trickster",
    "legend" : "the Mountebank of the Mountain",
    "avatar" : "the Overseer of the Masquerade",
  ]) );
}
