#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   string RACE_IS;
   npc::create();
   switch(random(4)) {

      case 0:
      RACE_IS = "human";
      break;

      case 1:
      RACE_IS = "dwarf";
      break;

      case 2:
      RACE_IS = "halfling";
      break;

      case 3:
      RACE_IS = "elf";
      break;
   }
   SetKeyName(RACE_IS + " guest");
   SetShort("a " + RACE_IS + " guest");
   SetId( ({ RACE_IS,"guest" }) );
   SetAdjectives( ({ RACE_IS, "tipsy" }) );
   SetLong("The " + RACE_IS + " is a guest of Lord of Vale Castle.  "
           "He looks slightly tipsy, but is still strong and rather "
           "awake.");
   SetRace(RACE_IS);
   SetGender("male");
  
   SetClass("rogue");
   SetLevel(13+random(3));
   if(RACE_IS == "human" || "elf") {
      SetCurrency("imperials",4 + random(20));
   }
   else {
      SetCurrency("nuggets",8 + random(16));
   }
   SetInventory( ([
                    VC_OBJ + "beer" : random(2)+1,
               ]) );
   AddAlcohol(10+random(9));
   SetMorality(random(50)-random(75));
}