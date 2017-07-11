/*   Portia  10-23-98
    A evoker leader for Malveillant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("carian");
  SetShort("Carian, the Royal Evoker");
  SetId( ({"carian", "evoker"}) );
  SetAdjectives( ({"royal"}) );
  SetLong("Carian is an enormous dark-elf with an ego to match. "
         "He seems as though he has great power and he knows it.");
  SetRace("dark-elf"); 
  SetGender("male");
  SetClass("evoker");
  SetTaughtSpheres( ({ "magical", "magical evokation" }) );
  
  SetTown("Malveillant");
  SetMorality(-200);
  SetLevel(60);
  SetCurrency("roni",random(40) + 20);
  
  SetInventory( ([
      MAL_OBJ + "/clothing/roy_leg"   : "wear leggings",
      MAL_OBJ + "/clothing/roy_shirt" : "wear shirt",
      MAL_OBJ + "/weapons/staff"      : "wield staff",
        ]) );
  
  SetFreeEquip( ([
       "/std/weapon/pole/staff" : 1,
        ]) );
  SetAction(13,
     "!say would you like to learn the art of evokation?");
  SetSpellBook( ([
   	 "bolt"           : 100,
   	 "disintegrate"   : 100,
   	 "mesmer barrier" : 100,
       ]) );
  SetCombatAction(70, ({
     "!cast mesmer barrier",
     "!cast disintergrate",
     "!cast bolt",
          }) );
  SetPlayerTitles( ([
      "newbie"      : "the Apprentice Evoker of Malveillant",
      "mortal"      : "the Evoker of Malveillant",
      "high mortal" : "the Supreme Evoker of Malveillant",
      "legend"      : "the High Evoker of Malveillant",
      "avatar"      : "the Master of Evokation",
      ]) );
  }
