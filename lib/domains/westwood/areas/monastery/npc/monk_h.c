#include <lib.h>
inherit LIB_SENTIENT;
#include "../monastery.h"

static void create() {
   sentient::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("happy monk");
   SetShort("a happy monk");
   SetId( ({ "monk" }) );
   SetAdjectives( ({ "happy" }) );
   SetLong("The monk smiles with joy and looks very happy to be alive "
           "and kicking.  Apparently, " + nominative(this_object()) + 
           " has been studying Eclat for some time to maintain such joy.");
   switch(random(6)) {
      case 0..4:
      SetRace("muezzin");
      break;
      case 5:
      switch(random(3)) {
         case 0:
         SetRace("gelfling");
         RemoveLanguage("Eltherian");
         SetLanguage("Oiseau",100,1);
         break;
         case 1:
         SetRace("dwarf");
         RemoveLanguage("Dwarvish");
         SetLanguage("Oiseau",100,1);
         break;
         case 2:
         SetRace("halfling");
         RemoveLanguage("Eltherian");
         SetLanguage("Oiseau",100,1);
         break;
      }
   }
   SetReligion("Eclat","Eclatish");
   if(random(2)) {
         SetClass("priest");
         SetSkill("melee combat",1,2);
         SetSpellBook( ([
                        "sanctify" : 100,
                        "mend" : 100,
            ]) );
         }
   else { 
         SetClass("fighter");
         SetSkill("melee combat",1,2);
         SetSkill("cloth armour",1,2);
      }
   SetLevel(40+random(5));
   SetAction(1,({ 
        "!laugh",
        "!giggle",
        "!smile",
        "!emote grins joyously.",
    "!speak in Oiseau Be happy forever!"
        }) );
   SetCombatAction(15, ({ 
                        "!disarm",
        "!speak in oiseau Please stop!", 
        "!cast sanctify",
        "!cast mend",
        }) );
   SetInventory( ([
        M_OBJ + "shirt" : "wear shirt",
        M_OBJ + "pants" : "wear pants",
        ]) );
   SetCurrency("cuicui", 5 + random(30));
   SetMorality(1000);
}
