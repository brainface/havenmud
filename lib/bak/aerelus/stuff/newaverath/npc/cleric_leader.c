#include <lib.h>
#include <std.h>
#include "../averath.h"
inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Florian Sordeau");
  SetId( ({ "florian", "sordeau", "priest", "averath_person" }) );
  SetShort("Florian Sordeau the High Priest of Aetarin");
  SetLong(
    "Florian is a very tall and well built man. He has a firm understanding "
    "of Aetarin ideals, and enforces them at every opportunity. He is clearly "
    "no stranger to battle, and seems to be missing part of his right ear. "
  ); 
          
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");    
  AddCurrency("ducats", random(100));
  SetMorality(9);
  SetClass("cleric");
  SetLevel(200); 
  
  SetUniqueSkills( ([
     "enchantment"  : 1,     
     "blunt attack" : 1,
     "evokation"    : 1,
     "healing"      : 2,
     "blunt defense": 2,
     "pole defense" : 2,
     "melee defense": 2,
     "bargaining"   : 3,     
     "slash defense": 3,
     "multi-weapon" : 3,
  ]) );
  
  SetTaughtSpheres( ({
    "clerical",
    "religion aetarin",
    "clerical evokation",
    "clerical enchantment",
    "clerical healing",
    }) );
    
  SetSpellBook( ([    
    "barrier of faith" : 100,    
    "harm body" : 100,
  ]) );
  
  SetAction(10, ({
    "!say It is better to die in battle, than live in dishonor."
    "!say Show bravery in life, and Aerelus the Patriarch of Honor will "
      "reward you in death.",
    "!say Be on the lookout for any conjurers, they are to be executed on "
      "sight!",    
    "!cast barrier of faith",     
   }) );
  SetCombatAction(16, ({
    "!cast harm body",     
  }) );
  SetReligion("Aetarin");
  SetTown("Averath");
  SetPlayerTitles( ([
    "newbie" : "the Aetarin Initiate",
    "mortal" : "the Priest of Aetarin",
    "hm" : "the Honorable Preacher",
    "legend" : "the Arbitrator",
    "avatar" : "the Divine Warrior"     
    //"fighter" : "of the Aetarin Crusade",
    //"bard" : "the Rapturous Composer",
    ]) );
  
  SetFreeEquip( ([
    STD_ARMOUR "shirt/studded_leather" : 1,
    "/std/weapon/blunt/mace" : 1,  
  ]) );
  
  SetInventory( ([
    "/std/weapon/blunt/war-hammer" : "wield hammer",
  ]) );
  }
