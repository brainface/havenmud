/*  Portia  10-23-98
     A necromancer leader for Malveillant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("mourin");
  SetShort("Mourin, the Evil One");
  SetId( ({"mourin"}) );
  SetAdjectives( ({"evil"}) );
  SetLong("Mourin is very frightening. His black eyes and pale skin "
          "contrast in a way that make him very intimidating. His demeanor "
          "suggests that he likes no living creature.");
  SetRace("dark-elf");
  SetTown("Malveillant"); 
  SetMorality(-2000);
  SetClass("necromancer");
  SetGender("male");
  SetLevel(40);
  SetInventory( ([
      MAL_OBJ + "/clothing/elf_tunic" : "wear tunic",
      MAL_OBJ + "/clothing/elf_leg"   : "wear leggings",
      MAL_OBJ + "/clothing/nec_cape"  : "wear cape",
      MAL_OBJ + "/weapons/staff" 			: "wield staff",
      ]) );
  SetCurrency("roni",random(150) + 50);
  SetAction(9, ({
      "!say would you like to learn of death, little one?"
    	}) );
  SetReligion("Soirin","Soirin");
  SetFreeEquip( ([
     "/std/weapon/pole/staff" : 1,
     ]) );
  
  SetSpellBook( ([
     "hunger"          : 100,
     "acid rain"       : 100,
     "energy field"    : 100,
     "chain lightning" : 100,
     "acid blast"      : 100,
     ]) );
  SetCombatAction(85, ({
     "!cast chain lightning",
     "!cast hunger",
     "!cast acid rain",
     "!cast energy field",
     "!cast acid blast",
     }) );
  SetPlayerTitles( ([
     "newbie"   : "the Dark One of Malveillant", 
     "mortal"   : "the Necromancer of Malveillant", 
     "hm" 		  : "the High Necromancer of Malveillant", 
     "legend"   : "the Supreme Necromancer", 
     "avatar"   : "the Bringer of Death", 
     "cavalier" : "the Dark Protector of Malveillant",
     ]) );
  }
