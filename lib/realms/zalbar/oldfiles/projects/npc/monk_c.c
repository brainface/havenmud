#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

void DoSomething();

static void create() {
   ::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("content monk");
   SetShort("a content monk");
   SetId( ({ "monk" }) );
   SetAdjectives( ({ "content" }) );
   SetLong("The monk is content, seeming surprised at some of the "
           "spontaneous laughter that often occurs.  Obviously, this "
           "monk has not been long at study.");
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   switch(random(6)) {
      case 0..4:
      SetRace("muezzin");
      break;
      case 5:
      switch(random(3)){
         case 0:
         SetRace("dwarf");
         RemoveLanguage("Dwarvish");
         SetLanguage("Oiseau",100,1);
         break;
         case 1:
         SetRace("gelfling");
         RemoveLanguage("Eltherian");
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
      SetClass("cleric");
      SetSkill("melee combat",1,2);
      SetSpellBook( ([
         "sanctify" : 100,
         ]) );
      }
   else { 
      SetClass("fighter");
      }
   SetLevel(120);
   SetCurrency("cuicui",8 + random(20));
   SetAction(1,({ 
   	"!emote smiles.",
   	"!emote laughs tentatively.",
        "!emote looks around at the happiness surrounding "
        "everything here, and sparkles begin appearing in "
        + possessive(this_object()) + " eyes." }) );
   SetCombatAction(40,({ 
        "!speak in Oiseau What are you "
        "doing, we are peaceful and .. and joyous!",
        "!cast sanctify",
        }) );
   SetMorality(600);
   SetInventory( ([
	M_OBJ + "pants" : "wear pants",
	]) );
}