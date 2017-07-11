#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

static void create() {
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
   SetKeyName("knife trainee");
   SetShort("a knife trainee");
   SetId( ({ "trainee","muezzin" }) );
   SetAdjectives( ({ "knife","young" }) );
   SetLong("This young muezzin looks for " + possessive(this_object()) +
           " teacher, preparing to train more in the skills of the knife "
           "weapons.  " + capitalize(nominative(this_object())) +
           " appears to be fairly proficient "
           "in those skills.");
   SetRace("muezzin");
   SetClass("fighter");
   SetSkill("knife combat",1, 1);
   SetLevel(20+random(5));
   SetInventory( ([
                    M_OBJ + "knif_t" : "wield knife in left hand",
               ]) );
   SetMorality(450);
   SetCurrency("cuicui",1 + random(25));
}
