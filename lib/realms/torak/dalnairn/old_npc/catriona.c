// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("catriona"); 
  SetId( ({ "catriona", "sorceress", "dalnairn_people" }) );
  SetShort("Catriona the Sorceress");  
  SetLong(
    "Catriona spends most of her time in the library here, studying the "
    "ancient books for any magical knowledge. There is a surprising lack of "
    "magical literature in the city, but she seems like she knows enough "
    "to be able to teach a novice."    
  	);
  SetFriends("dalnairn_people");
  SetRace("dark-dwarf");
  SetGender("female");
  SetClass("evoker");
  SetLevel(60);
  SetReligion("Soirin");
  SetMorality(-400);
  SetCurrency("shards", random(80));
  SetSpellBook( ([
  	"mesmer barrier"	: 100,
  	"chain lightning" : 100,
  	"disintegrate"    : 100,
  	"paralysis"       : 100,
  	]) );
  SetAction(5, ({
    "!speak Would you like to learn about magic?",
  	}) );
  SetCombatAction(75, ({
    "!cast mesmer barrier",
    "!cast chain lightning",
    "!cast disintegrate",
    "!cast paralysis",
    }) );
  SetInventory( ([
    DAL_OBJ + "pants": "wear pants",
    DAL_OBJ + "shirt" : "wield shirt",
    DAL_OBJ + "shoes" : "wear shoes",
    "/std/weapon/pole/staff" : "wield staff"
  	]) );
  
  SetTown("Dalnairn");
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,    
  ]) );  
  SetPlayerTitles( ([
    "newbie" : "the Apprentice",
    "mortal" : "the Menial Mage",
    "hm"     : "the Worthy Wizard",
    "legend" : "the Cunning Conjurer",
    "avatar" : "the Meritorious Manipulator of Energy",
  ]) );
}
