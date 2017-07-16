// Coded by Zeratul
// 3-28-2000

#include <lib.h>
#include "../drazh.h"

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("citizen");
  SetId( ({"citizen","skaven","wander"}) );
  SetShort("an average looking citizen");
  SetAdjectives( ({"average","looking","male","skaven"}) );
  SetLong(
     "This average looking citizen wanders about the town, without any sort "
     "of special look on his face. He goes about his daily duties, looking "
     "as average as the next skaven to pass by. "
   );
 
  SetGender("male");
  SetRace("skaven");
  SetClass("rogue");
  SetReligion("Soirin");
  SetLevel(3 + random(3));
  SetCurrency("roni",random(50));
  SetMorality(-800);
  SetAction(3, ({
     "!yawn",
     "!speak We need to defend ourselves from invaders!",
     "!speak Its a good thing I moved here, I prefer to live with my own kind. ",
     "!speak I wonder why I used to live in that dark-elf town.",
   }) );
  SetCombatAction(6, ({
     "!speak Get away from me!",
     "!speak Help me!",
   }) );
  SetInventory( ([
     ]) );
}

