#include <lib.h>
inherit LIB_SENTIENT;
#include "../monastery.h"

static void create() {
   sentient::create();
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
   SetReligion("Eclat","Eclatish");
   SetClass("cleric");
   SetClass("fighter");
   SetSkill("melee attack",120,1);
   SetSkill("melee defense",120,1);
   SetLevel(50);
   SetRace("muezzin");
   SetSpellBook( ([
                    "sanctify" : 100,
               ]) );
   SetAction(1,({ "!speak in oiseau Peace and joy to all!",
                  "!emote doubles over with laughter.",
                  "!laugh","!giggle","!dance","!bounce",
                  "!emote bends to smell a flower, smiling "
                  "with joy.","!emote raises " + 
                  possessive(this_object()) + 
                  " face toward the sky and smiles." }) );
   SetCombatAction(40,({ "!cast sanctify","!cast sanctify",
                         "!speak in oiseau I beg you to stop!  This "
                         "is not a joyous act!" }) );
   SetInventory( ([
                    M_OBJ + "robe" : "wear robe",
                    M_OBJ + "pants" : "wear pants",
               ]) );
   SetCurrency("cuicui",6000);
   SetMorality(900);
}