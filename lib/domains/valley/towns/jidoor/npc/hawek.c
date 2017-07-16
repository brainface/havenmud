/* Hawek -- Ranger Leader
 * Zaxan Zimtafarous@Haven
 */
#include <lib.h>
#include <std.h>
#include "../jidoor.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetReligion("Magildan","Magildan");
  SetShort("Hawek, the Lord of Jidoor's Forests");
  SetKeyName("hawek");
  SetId( ({"hawek","ranger","jidoor_npc",}) );
  SetLong("Hawek is a young and energetic sprite, who seems "
          "filled with a love of nature.  He looks capable of "
          "defending himself but looks quite friendly.");
  SetRace("sprite");
  SetTown("Jidoor");  
  SetClass("ranger");
  SetGender("male");
  SetLevel(50);
  SetSpellBook( ([
  	"tangle"         : 100,
  	"natural charge" : 100,
  	"ice storm"      : 100,
  	"wall of wood"   : 100,	
  	]) );
  SetAction(1, ({
    "!say So are you interested becoming a ranger?",
    "!emote smiles at you.",
    }) );
  SetCombatAction(30, ({
    "!cast tangle",
    "!cast wall of wood",
    "!cast natural charge",
    "!cast ice storm",
    }) );
  SetPlayerTitles( ([
     "newbie" : "the Forester of Jidoor ",
     "mortal" : "the Ranger of Jidoor",
     "hm"     : "the Grand Ranger of Jidoor",
     "legend" : "the Lord of Jidoor's Forests",
     "avatar" : "the Protector of Nature",
     ]) );
   SetFreeEquip( ([ 
      STD_PROJECTILE + "bow_long_newbie" : 1,
   ]) );    
   SetInventory( ([ 
      STD_PROJECTILE + "long_bow" : "wield bow",
      JID_OBJ + "/clothing/vs_necro_robe" : "wear robe",
   ]) );
  }
