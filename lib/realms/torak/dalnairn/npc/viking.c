// Torak@haven 2019
// dalnairn recode 2014-2019 (jesus this is taking forever)

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("skarla");  
  SetId( ({ "skarla", "spearmaiden", "maiden", "dalnairn_people" }) );
  SetShort("Skarla the Spearmaiden");  
  SetLong(
    "Skarla is a tall and muscular orc. Her head is shaved "
    "clean to the skin. Her ears have numerous piercings. ",
  );
  SetFriends("dalnairn_people");  
  SetRace("orc");
  SetGender("female");
  SetClass("viking");
  SetLevel(40);
  SetUnique(1);
  SetReligion("Damhair");
  SetMorality(-300);
  SetCurrency("shards", random(400)+10);
  SetAction(4, ({
    "!emote eyes you over.",
    "!emote snears at you vicously.",
    "!emote grins at you hungrily.",
    "!emote belches loudly!",
  }) );
  SetCombatAction(5, ({
    "!disorient",
  }) );
  SetInventory( ([
    "/std/armour/free_armour/large/oldpants" : "wear pants",
    "/std/armour/free_armour/large/oldvest"  : "wear vest",
    "/std/armour/free_armour/large/oldboots" : "wear boots",
    DAL_OBJ + "knife" : "wield knife",
  ]) );
  SetTown("Dalnairn");
  SetFreeEquip( ([
    "/std/weapon/slash/shortsword" : 1,
    "/std/weapon/hack/hand-axe" : 1,
  ]) );  
  SetPlayerTitles( ([
    "newbie"      : "the Sulking Swabie",
    "mortal"      : "the Rowdy Rower",
    "hm"          : "the Perilous Pillager",
    "legend"      : "the Vicious Viking",
    "avatar"      : "Captain $N",
    "deity"       : "Admiral $N",
    "necromancer" : "the Sea Ravager",
  ]) );
}
