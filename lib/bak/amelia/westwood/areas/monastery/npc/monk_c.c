#include <lib.h>
inherit LIB_SENTIENT;
#include "../monastery.h"

static void create() {
   sentient::create();
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
   SetClass("cleric");
   SetClass("fighter");
   SetLevel(20+random(8));
   SetSkill("melee attack",72,1);
   SetSkill("melee defense",72,1);
   SetCurrency("cuicui",4500+random(220));
   SetAction(1,({ "!emote smiles.","!emote laughs tentatively.",
                  "!emote looks around at the happiness surrounding "
                  "everything here, and sparkles begin appearing in "
                  + possessive(this_object()) + " eyes." }) );
   SetCombatAction(40,({ "!speak in Oiseau What are you "
                          "doing, we are peaceful and .. and joyous!" }) );
   SetMorality(600);
   SetInventory( ([
				M_OBJ + "pants" : "wear pants",
			]) );
}
