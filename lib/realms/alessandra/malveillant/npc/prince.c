/*  Portia  10-21-98
   A prince for the town of Malviellant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("Prince Marikian");
  SetShort("Marikian, Prince of the Dark-Elves");
  SetId( ({"marikian", "prince", "prince of the dark-elves"}) );
  SetAdjectives( ({ }) );
  SetLong("The prince is very young, but appears very strong. "
          "He seems to know how to defend himself and his home that he "
          "is so very proud of.");
  SetRace("dark-elf"); 
  SetMorality(-1200);
  SetGender("male");
  SetClass("cavalier");
  SetSkill("knife combat",1,1);
  SetSkill("cloth armour",1,1);
  SetLevel(110);
  SetTown("Malveillant");
  SetCurrency("roni",random(400) + 750);
  SetLocalCurrency("roni");
  SetTax(20);
  SetInventory( ([
     MAL_OBJ + "/clothing/p_cape"    : "wear cape",
     MAL_OBJ + "/clothing/roy_shirt" : "wear shirt",
     MAL_OBJ + "/clothing/roy_leg"   : "wear leggings",
     MAL_OBJ + "/clothing/g_boots"   : "wear boots",
     MAL_OBJ + "/weapons/p_dagger"   : "wield dagger",
     MAL_OBJ + "/weapons/elf_rapier" : "wield rapier",
     ]) );
  SetAction(10, ({
     "!say Would you like to become a citizen of my fine town?"
     }) );
  SetCombatAction(10 , ({
     "!disarm",
  	 }) );
  }
