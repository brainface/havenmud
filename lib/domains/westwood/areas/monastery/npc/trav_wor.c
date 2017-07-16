#include <lib.h>
inherit LIB_SENTIENT;
#include "../monastery.h"

static void create() {
   sentient::create();
   SetTown("Soleil");
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("travelling worshipper");
   SetShort("a travelling worshipper of Eclat");
   SetId( ({ "worshipper","worshipper of eclat","traveller",
             "traveler" }) );
   SetAdjectives( ({ "eclatish","eclat","travelling" }) );
   SetLong("The worshipper has been on the road for a long time so "
           "that " + nominative(this_object()) + " is fairly tired and "
           "worn out.  However, " + nominative(this_object()) + " seems "
           "very happy and pleased with what is going on around " 
           + objective(this_object()) + ".");
   SetReligion("Eclat","Eclat");
   
   
   switch(random(2)) {
      case 0:
      SetRace("muezzin");
      SetClass("fighter");
      SetSkill("melee combat",1,2);
      SetSkill("cloth armour",1,3);
      SetLevel(random(5)+23);
      SetCurrency("cuicui",5+random(23));
      
      break;
      case 1:
      switch(random(3)){
         case 0:
         SetRace("dwarf");
         RemoveLanguage("Dwarvish");
         SetLanguage("Oiseau",100,1);
         SetClass("fighter");
         SetSkill("melee combat",1,2);
         SetSkill("cloth armour",1,3);
         SetLevel(random(5)+23);
         SetCurrency("nuggets",5+random(23));
         break;
         case 1:
         SetRace("gelfling");
         RemoveLanguage("Eltherian");
         SetLanguage("Oiseau",100,1);
         SetClass("fighter");
         SetSkill("melee combat",1,2);
         SetSkill("cloth armour",1,3);
         SetLevel(random(5)+23);
         SetCurrency("imperials",5+random(23));
         break;
         case 2:
         SetRace("halfling");
         RemoveLanguage("Eltherian");
         SetLanguage("Oiseau",100,1);
         SetClass("fighter");
         SetSkill("melee combat",1,2);
         SetSkill("cloth armour",1,3);
         SetLevel(random(5)+23);
         SetCurrency("imperials",5+random(23));
         break;
      }
   }

   SetInventory( ([
    	M_OBJ + "cloak_t" : "wear cloak",
      ]) );
   
   SetMorality(500);

}   
