/*  Portia  10-24-98
    A woman for the town.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("woman");
  SetShort("a dark-elf woman");
  SetId( ({"woman", "dark-elf"}) );
  SetAdjectives( ({"dark-elf"}) );
  SetLong("This woman looks to be only a mere citizen of "
          "Malveillant. She appears to be busy with her chores.");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetGender("female");
  
  SetClass("rogue");
  SetLevel(10);
  SetCurrency("roni",random(20)+1);
  SetInventory( ([
      MAL_OBJ + "/clothing/elf_shirt" : "wear shirt",
      MAL_OBJ + "/clothing/elf_pants" : "wear pants",
            ]) );
  SetAction(7, ({
  	  "!say I am glad this work will be done soon.",
  	  "!say When will we be done moving the store?",
  	  "!emote packs some items of clothing away.",
  	  }) );
  SetFriends("child");
  SetFriends("man");
  }
