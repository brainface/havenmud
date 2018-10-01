// Dalnairn
// Aerelus
// updated for dalnairn recode torak@haven 2017

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  ::create();
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
    "!speak Would you like to learn of the Prince of Deception?",
  	}) );
  SetCombatAction(50, ({
  	"!cast barrier of faith",
  	"!cast pain touch",
  	"!cast poison arrow",
  	}) );
  SetSpellBook( ([
  	"barrier of faith"  : 100,
  	"pain touch"        : 100,
  	"poison arrow"      : 100,
  	]) ); 
  		
  SetInventory( ([
    DAL_ARM + "pants" : "wear pants",
    DAL_ARM + "shirt" : "wear shirt",
    DAL_ARM + "shoes" : "wear shoes",
    DAL_WPN + "hooked_axe" : "wield axe",
  	]) );
  
  SetTown("Dalnairn"); 
  SetReligion("Soirin");
  SetMorality(-1200);
  SetFreeEquip( ([
    "/std/weapon/knife/small_knife" : 2,    
  	]) );
  SetPlayerTitles( ([
    "newbie" : "the Profiteering Prophet", // no
    "mortal" : "the Zealous Collector", // no
    "hm"     : "the Avaricious Abbot",  // no
    "legend" : "the Rapacious Rector",  // no
    "avatar" : "the Venal Vicar of the Obsidian Mountain",  // no
  	]) );
  SetTaughtSpheres( ({
    "illusion"
    "clerical healing"
    "clerical evokation", 
    "religion soirin", 
    "clerical"
    }) );
}
