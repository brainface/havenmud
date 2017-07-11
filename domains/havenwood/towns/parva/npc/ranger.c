#include <lib.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   
   
   SetKeyName("Alae");
   SetShort("Alae, the Young Ranger");
   SetId( ({ "alae", "ranger" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("Alae is a young human that has spent all her life "
           "learning about being a ranger.  She now teaches "
           "those just starting out on their ranger lives "
           "the basic skills of existence, and helps them "
           "with a few basic items, if they ask her to join.");
   
   SetGender("female");
   SetRace("human");
   SetClass("ranger");
   SetLevel(30);
   SetTown("Parva");
   SetMorality(500);
   SetInventory( ([
     ]) );
   SetPlayerTitles( ([
     "newbie"    : "the Scout of the Forest",
     "mortal"    : "the Forest Walker",
     "hm"        : "the Master of Animals",
     "legend"    : "the Forest Lord",
     "avatar"    : "the Supreme Ruler of the Woods",
     ]) );
   SetAction(1,({ 
   		"!smile",
      "!say Join up and be a ranger!  "
      "It's a great life.",
      "!say Concentration is a skill all rangers will learn to master. "
      "It's important for every day life, too!",
      "!say Rangers are respected everywhere!",
      "!say Protect the forests!" 
      }) );
   SetCombatAction(40,({ 
   		"!say Stop that! Get away!",
   		"!cast terra",
      "!shout Help!  Help!!",
      "!cast vermin horde",
      "!say Someone help me get this thug out of Parva!",
      "!cast tangle",
      "!cast condense",
      "!say Stop it!",
      "!cast natural veil",
      "!say You'll pay for this!",
      }) );
   SetFreeEquip( ([
     	PARVA_OBJ "ranger_slash" : 1,
     	]) );
  SetSpellBook( ([
      "natural veil" : 100,
      "terra" 	     : 100,
      "vermin horde" : 100,
      "tangle" 			 : 100,
      "condense air" : 100,
      ]) );
  SetInventory( ([
    	PARVA_OBJ "ranger_slash" : "wield sword",
    	]) );
}	
