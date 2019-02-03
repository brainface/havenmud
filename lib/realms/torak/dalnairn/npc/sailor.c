// Torak@haven 2019
// dalnairn recode 2014-2019 (jesus this is taking forever)

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("devon");  
  SetId( ({ "devon", "", "dalnairn_people" }) );
  SetShort("Devon");  
  SetLong(
    "Devon is a short and stocky dark-dwarf. "
    "His skin is lined and dried like hard leather. "
    "He has a bright red close cut and cropped beard."
  );
  SetFriends("dalnairn_people");  
  SetRace("dark-dwarf");

  SetGender("male");
  SetClass("sailor");
  SetLevel(40);
  SetUnique(1);
  SetReligion("Damhair");
  SetMorality(-300);
  SetCurrency("shards", random(400)+10);
  SetAction(2, ({
    "!emote tries to order another ale.",
    "!emote stumbles slightly.",
    "!emote grins at you knowingly.",
    "!emote belches loudly!",
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
    "newbie"  : "the Powder Monkey",
    "mortal"  : "the Able Bodied Sailor",
    "hm"      : "the Mate",
    "legend"  : "the Master Gunner",
    "avatar"  : "Captain $N",
    "deity"   : "Admiral $N",
    "fighter" : "the Merchant Marine",
    "rogue"   : "the Rigging Runner",
    "bard"    : "the Lookout Crow",
  ]) );
}
