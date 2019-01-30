// Dalnairn
// Aerelus
//
// torak@haven
// recoded from evoker to necromancer for dalnairn recode 2019

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();  
  SetKeyName("catriona"); 
  SetId( ({ "catriona", "sorceress", "dalnairn_people" }) );
  SetShort("Catriona");
  SetLong(
//    "Catriona spends most of her time in the temple here, studying the "
//    "ancient books for any magical knowledge. There is a surprising lack of "
//    "magical literature in the town, but she seems like she knows enough "
//    "to be able to teach a novice."
    "Catriona is a sturdy deep dwarf dressed in rather mundane regalia. "
    "She is missing her left eye, with a horrid scar marring her face. "
    "A layer of dirt and sand covers her. " 
  	);
  SetUnique(1);
  SetFriends("dalnairn_people");
  SetRace("dark-dwarf");
  SetGender("female");
  SetClass("necromancer");
  SetLevel(60);
  SetReligion("Soirin");
  SetMorality(-400);
  SetCurrency("shards", random(80));
  SetSpellBook( ([
  	"drain soul"            : 100,
  	"hunger"                : 100,
  	"necromantic shield"    : 100,
  	"acid rain"             : 100,
  	]) );
  SetAction(5, ({
    "!speak Would you like to learn about death?",
  	}) );
  SetCombatAction(75, ({
    "!cast necromantic shield",
    "!cast drain soul",
    "!cast hunger",
    "!cast acid rain",
    }) ); 
  SetInventory( ([
    DAL_OBJ + "pants"        : "wear pants",
    DAL_OBJ + "shirt"        : "wear shirt",
    DAL_OBJ + "shoes"        : "wear shoes",
    "/std/weapon/pole/staff" : "wield staff"
  	]) );
  
  SetTown("Dalnairn");
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,    
  ]) );  
  SetPlayerTitles( ([
    "newbie" : "the Shrouded Apprentice",
    "mortal" : "the Dark Practitioner",
    "hm"     : "the Dark Artist",
    "legend" : "the Lord of Pain",
    "avatar" : "the Dreaded Overlord of Despair",
    "deity"  : "the Undying",
  ]) );
}
