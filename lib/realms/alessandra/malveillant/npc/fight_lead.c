/*  Portia 10-23-98
   A fighter leader.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("xavien");
  SetShort("Xavien the fighter");
  SetId( ({"xavien", "fighter"}) );
  SetLong("Xavien is a brute of a dark-elf, and takes pride in "
         "his size. His skills do not fit into the Royal Guard's "
        "description, but he defends the town nevertheless.");
  SetRace("dark-elf"); 
  SetTown("Malveillant");
  SetMorality(-200);
  SetClass("fighter");
  SetSkill("disarm",250,1);
  SetLevel(70);
  SetGender("male");
  SetCurrency("roni",random(500) + 40);
  SetInventory( ([
      MAL_OBJ + "/weapons/gl_sword"     : "wield sword",
      MAL_OBJ + "/clothing/g_pants"     : "wear pants",
      MAL_OBJ + "/clothing/g_boots"     : "wear boots",
      MAL_OBJ + "/clothing/g_medallion" : "wear medallion",
      MAL_OBJ + "/clothing/lead_plate"  : "wear plate",
         ]) );
  SetAction(5, ({
      "!say would you like to join my team in the defense of our "
      "beloved town?"
    	}) );
  SetCombatAction(5, ({
      "!disarm"
    	}) );
  SetFreeEquip( ([
    	"/std/weapon/slash/sword" : 1,
       ]) );
  
  SetPlayerTitles( ([
       "newbie" : "the Initiate Guard of Malveillant",
       "mortal" : "the Guard of Malveillant",
       "hm"     : "the Protector of Malveillant",
       "legend" : "the High Protector of Malveillant",
       "avatar" : "the Supreme Protector of Malveillant",
       ]) );
  }
