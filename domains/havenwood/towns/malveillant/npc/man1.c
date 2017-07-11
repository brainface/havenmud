/*  Portia  11-6-98
   A generic man.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("man");
  SetShort("a tall man");
  SetId( ({"man"}) );
  SetAdjectives( ({"tall"}) );
  SetGender("male");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetClass("rogue");
  SetLevel(30);
  SetInventory( ([
      MAL_OBJ + "/clothing/tunic" : "wear tunic",
      MAL_OBJ + "/clothing/leggings" : "wear leggings",
      ]) );
  SetCurrency("roni",random(150) + 30);
  SetAction(6, ({
     "!smile"
     }) );
  
  SetLong("This man is rather tall, and has all the striking features "
          "of a dark-elf. He appears to be about 50 years of age, but "
          "still very strong.");
  }
