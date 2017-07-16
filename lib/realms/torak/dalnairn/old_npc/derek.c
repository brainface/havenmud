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
    "Derek is a dark-dwarf who is looked up to by all in Dalnairn. He is a devout "
    "follower of Soirin, and knows much of the old teachings. Given his "
    "importance in Dalnairn society, he is a very wealthy dwarf. He is always "
    "in need of new recruits to help spread the word of Alessandra to "
    "generations to come."    
  	); 
  SetFriends("dalnairn_people"); 
  SetRace("dark-dwarf");
  SetGender("male");
  SetClass("priest");
  SetLevel(70);

  SetCurrency("shards", random(1000)+5);
  SetAction(5, ({
    "!speak Would you like to learn of the Dark Mistress?",
  	}) );
  SetCombatAction(50, ({
  	"!cast barrier of faith",
  	"!cast pain touch",
  	"!cast poison arrow",
  	}) );
  SetSpellBook( ([
  	"barrier of faith"	: 100,
  	"pain touch"        : 100,
  	"poison arrow"      : 100,
  	]) );
  		
  SetInventory( ([
    DAL_OBJ + "pants": "wear pants",
    DAL_OBJ + "shirt" : "wear shirt",
    DAL_OBJ + "shoes" : "wear shoes",
    DAL_OBJ + "hooked_axe" : "wield axe",
  	]) );
  
  SetTown("Dalnairn"); 
  SetReligion("Soirin");
  SetMorality(-1200);
  SetFreeEquip( ([
    "/std/weapon/hack/hand-axe" : 2,    
  	]) );
  SetUniqueSkills( ([
    "blunt combat" : 0,
    "hack combat" : 1,
    "stealth" : 2,
  	]) );
  SetPlayerTitles( ([
    "newbie" : "the Profiteering Prophet",
    "mortal" : "the Zealous Collector",
    "hm"     : "the Avaricious Abbot",
    "legend" : "the Rapacious Rector",
    "avatar" : "the Venal Vicar of the Obsidian Mountain",
  	]) );
  SetTaughtSpheres( ({
  	"clerical necromancy"
    "clerical evokation", 
    "religion soirin", 
    "clerical"
    }) );
}
