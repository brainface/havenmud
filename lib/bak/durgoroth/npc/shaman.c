// Title: Destroyed Grymxoria Town
// File: shaman.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1998
//
// Abstract: Sharess, the Shaman leader of Grymxoria
//
// Revision History: 
//

#include <lib.h>
#include <damage_types.h>
inherit LIB_LEADER;
#include "../durgoroth.h"

static void create() {
    leader::create();
    SetKeyName("Sharess");
    SetRace("daemon");
    SetClass("shaman");
    RemoveSkill("evokation");
    SetSkill("enchantment", 1, 1);
    SetLevel(60);
    SetGender("female");
    SetProperty("durgorothNPC",1);
    SetTown("Durgoroth");
    SetReligion("Saahagoth","Saahagoth");
    SetMorality(-1500);
    SetShort("Sharess, the Master Shaman of Durgoroth");
    SetId( ({ "sharess","master shaman","master","shaman" }) );
    SetLong("Sharess is a small, slight Daemoness, who looks "
        		"to be quite intelligent and swift, if weak for a "
        		"Daemon. She is the leader of the Shamans of Durgoroth "
       		  "and is said to be the keeper of knowledge of many secret "
        		"and arcane things.");
    SetCurrency("crystals", 50 + random(500));
    SetPlayerTitles(  ([
        "newbie" : "the Lowly Maggot, Initiate Shaman",
        "mortal" : "the Instrument of Terror",
        "hm" 		 : "the Feared Shaman of Saahagoth",
        "legend" : "the Bringer of Evil and Fear",
        "avatar" : "the Nightmare of Kailie",
        ]) );
    SetFriends(({"daemon","daemon guard","daemoness"}));
    SetTaughtSpheres( ({ 
    	"magical", 
    	"magical enchantment",
      "magical necromancy",
      "clerical", 
      "clerical enchantment",
      "clerical necromancy",
      "religion saahagoth",
      }) );
    SetSpellBook( ([
        "veil from beyond" : 100,
        "wither" : 100,
        "vampiric touch" : 100,
        "blindness" : 100,
        "paralysis" : 100,
        "ethereal touch" : 100,
        "earth touch" : 100,
        "pain touch" : 100,
        "cause bleeding" : 100,
        ]) );
    SetMeleeDamageType(SLASH);
    SetMeleeAttackString("claws");
  	SetUniqueSkills( ([
       "enchantment" : 1,
       "evokation" : 0,
    	 ]) );
    }
