/*   Portia  10-23-98
   An enchanter leader for Malveillant. 
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("lurian");
  SetShort("Lurian, the Royal Enchanter");
  SetId( ({"lurian", "enchanter" }) );
  SetAdjectives( ({"royal"}) );
  SetLong("Lurian is a tall man with curiously dark eyes. "
          "He seems to feel that he is more knowledgable than "
          "everyone else and radiates an aura of confidence.");
  SetGender("male");
  SetRace("dark-elf"); 
  SetTown("Malveillant");
  SetMorality(-200);
  SetClass("enchanter");  
  SetLevel(50);
  SetTaughtSpheres( ({ "magical", "magical enchantment" }) );
  SetCurrency("roni",random(10) + 30);

  SetAction(10,
       "!say would you like to learn the ways of enchantment?");
  SetInventory( ([
     	MAL_OBJ + "/clothing/roy_leg"   : "wear leggings",
     	MAL_OBJ + "/clothing/roy_shirt" : "wear shirt",
     	MAL_OBJ + "/weapons/staff"     : "wield staff",
     	]) );
  SetFreeEquip( ([
      "/std/weapon/pole/staff" : 1,
          ]) );
  SetSpellBook( ([
   		"mesmer barrier"  : 100,
   		"chain lightning" : 100,
   		"paralysis" 			: 100,
      ]) );
  SetCombatAction(70, ({ 
      "!cast mesmer barrier",
      "!cast chain lightning",
      "!cast paralysis",
      }) );
  SetPlayerTitles( ([
     "newbie" 	   : "the Apprentice Enchanter of Malveillant",
     "mortal" 	   : "the Enchanter of Malveillant",
     "high mortal" : "the Master Enchater of Malveillant",
     "legend"      : "the High Enchanter of Malviellant",
     "avatar"      : "the High Lord of Enchantment",
     ]) );
  
  }
