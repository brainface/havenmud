/*  Portia  11-6-98
   A citizen.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("citizen");
  SetShort("a citizen of Malveillant");
  SetId( ({"citizen"}) );
  SetGender("male");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetClass("rogue");
  SetLevel(20);
  SetLong("The dark-elf male has a striking appearance. His "
          "hair is as black as midnight to a human, and his eyes "
          "shimmer against his snow white skin. He is very well "
          "built and appears to have very strong arms.");
  SetCurrency("roni",random(30) + 20);
  SetInventory( ([
      MAL_OBJ + "clothing/elf_tunic"    : "wear tunic",
      MAL_OBJ + "clothing/elf_leggings" : "wear leggings",
      MAL_OBJ + "clothing/elf_boots"    : "wear boots",
    	]) );
  SetAction(7,
      "!smile warmly");
  }
