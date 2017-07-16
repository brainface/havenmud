#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

static void create() {
   npc::create();
   SetProperty("monasterynoleave",1);
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("Eclat student");
   SetShort("an Eclat student");
   SetId( ({ "student" }) ); 
   SetAdjectives( ({ "eclat","eclatish" }) );
   SetLong("The student smiles happily, prepared to take in all "
           + nominative(this_object()) + " can about Eclat.");
   switch(random(6)) {
      case 0..4:
      SetRace("muezzin");
      break;
      case 5:
      switch(random(10)){
         case 0..1:
         SetRace("elf");
         RemoveLanguage("Eltherian");
         SetLanguage("Oiseau",100,1);
         break;
         case 2..3:
         SetRace("dwarf");
         RemoveLanguage("Dwarvish");
         SetLanguage("Oiseau",100,1);
         break;
         case 4..6:
         SetRace("human");
         RemoveLanguage("Enlan");
         SetLanguage("Oiseau",100,1);
         break;
         case 7..8:
         SetRace("gelfling");
         RemoveLanguage("Eltherian");
         SetLanguage("Oiseau",100,1);
         break;
         case 9:
         SetRace("halfling");
         RemoveLanguage("Eltherian");
         SetLanguage("Oiseau",100,1);
         break;
      }
   }
   SetReligion("Eclat","Eclatish");
   SetClass("cleric");
   SetClass("fighter");
   SetSkill("melee attack",20);
   SetSkill("melee defense",20);
   SetLevel(20+random(3));
   SetAction(1,({ "!emote listens intently.","!emote looks around "
                  "with interest.","!smile" }) );
   SetCombatAction(5,({ "!speak in Oiseau Help!",
                        "!speak in Oiseau Stop this, I'm just "
                        "trying to be joyous!" }) );
   SetMorality(200);
   SetCurrency("cuicui",400);
}
