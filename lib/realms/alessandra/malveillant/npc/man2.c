/*  Portia  11-6-98
   A generic guy.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("man");
  SetShort("a short man");
  SetId( ({"man"}) );
  SetAdjectives( ({"short"}) );
  SetGender("male");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetClass("rogue");
  SetLevel(20);
  SetCurrency("roni",random(15) + 10);
  SetInventory( ([
      MAL_OBJ + "/clothing/elf_shirt" : "wear shirt",
      MAL_OBJ + "/clothing/elf_pants" : "wear pants",
      ]) );
  SetLong("This short dark-elf seems to have made up for what "
         "he lacks in height with his size. He has very strong arms and a "
         "powerful grip.");
  }
