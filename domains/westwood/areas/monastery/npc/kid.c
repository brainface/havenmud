#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

static void create() {
   string furcolor;
   npc::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   switch(random(2)){
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   switch(random(3)) {
     case 0:
     furcolor = "rich dark brown";
     break;
     case 1:
     furcolor = "chocolate light brown";
     break;
     case 2:
     furcolor = "beautiful pure white";
     break;
   }
   SetKeyName("young muezzin");
   SetShort("a muezzin child");
   SetId( ({ "muezzin","child","kid" }) );
   SetAdjectives( ({ "young","muezzin" }) );
   SetLong("Covered with fur, the muezzin child smiles impishly with "
           "the joy of youth.  " + possessive(this_object()) + " fur is "
           "a " + furcolor + " color.");
   SetClass("fighter");
    SetRace("muezzin");
    SetLevel(1+random(2));
   switch(random(2)) {
      case 0:
      SetInventory( ([
                       M_OBJ + "kidclub" : "wield stick in right hand",
                  ]) );
      
      break;
      case 1:
      SetInventory( ([
                       M_OBJ + "kidpole" : "wield stick in right hand",
                  ]) );
      
      break;
   }
   SetMorality(600);
}