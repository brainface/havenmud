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
   SetKeyName("joyous monk");
   SetShort("a joyous monk");
   SetId( ({ "monk","joyous" }) );
   SetAdjectives( ({ "joyous" }) );
   SetLong("The joyous monk has a great aura of peace around " 
           + objective(this_object()) + ", coating the area with joy and "
           "life.  " + capitalize(nominative(this_object())) + " looks "
           "quite confident, and carries " + reflexive(this_object())
           + " with great poise and life.");
   SetReligion("Eclat","Eclat");
   SetRace("muezzin");
   if(random(2)) {
      SetClass("priest");
      SetSkill("melee combat",1,2);
      SetSpellBook( ([
         "sanctify" : 100,
         "heal"     : 100,
         ]) );
      }
   else { 
      SetClass("fighter");
      SetSkill("melee combat",1,2);
      SetSkill("cloth armour",1,2);
      }
   SetLevel(50 + random(15));
   
   SetAction(1,({ 
   		"!speak in oiseau Peace and joy to all!",
      "!emote doubles over with laughter.",
      "!laugh",
      "!giggle",
      "!dance",
      "!bounce",
      "!emote bends to smell a flower, smiling "
      "with joy.","!emote raises " + possessive(this_object()) + 
      " face toward the sky and smiles." }) );
   SetCombatAction(15,({ 
   		"!cast sanctify",
   		"!cast heal",
   		"!disarm",
   		"!disorient",
   		"!speak in oiseau I beg you to stop!  This "
       "is not a joyous act!" }) );
   SetInventory( ([
        M_OBJ + "robe" : "wear robe",
        M_OBJ + "pants" : "wear pants",
        ]) );
   SetCurrency("cuicui", 15 + random (50));
   SetMorality(1000);
}
