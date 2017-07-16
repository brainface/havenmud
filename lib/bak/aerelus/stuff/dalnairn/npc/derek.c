// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("derek"); 
  SetId( ({ "derek", "kirk", "soirin", "priest", "dalnairn_people" }) );
  SetShort("Derek Kirk the Soirin Priest");  
  SetLong(
    "Derek is a man who is looked up to by all in Dalnairn. He is a devout "
    "follower of Soirin, and knows much of the old teachings. Given his "
    "importance in Duergar society, he is a very wealthy man. He is always "
    "in need of new recruits to help spread the word of Alessandra to "
    "generations to come."    
  ); 
  SetFriends("dalnairn_people"); 
  SetRace("dwarf");
  SetGender("male");
  SetClass("cleric");
  SetLevel(70);
  SetReligion("Soirin");
  SetMorality(-200);
  SetCurrency("shards", random(1000));
  SetAction(5, ({
    "!speak Would you like to learn of the Dark Mistress?",
  }) );
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );
  
  SetTown("Dalnairn");  
  SetFreeEquip( ([
    "/std/weapon/hack/hand-axe" : 2,    
  ]) );
  SetUniqueSkills( ([
     "evokation" : 1,
     "hack attack" : 1,
     "bargaining" : 1,
     "enchantment" : 2,
     "stealth" : 2,
     "hack defense" : 2,
     "multi-weapon" : 2,
     "pierce defense" : 2,
     "slash defense" : 3,
     "knife defense" : 3,
     "fishing" : 3,     
     "healing" : 3,
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Profiteering Prophet",
    "mortal" : "the Zealous Collector",
    "hm" : "the Avaricious Abbot",
    "legend" : "the Rapacious Rector",
    "avatar" : "the Venal Vicar of the Obsidian Mountain",
  ]) );
  SetTaughtSpheres( ({"clerical healing", "clerical enchantment", 
    "clerical evokation", "religion soirin", "clerical"}) );
}