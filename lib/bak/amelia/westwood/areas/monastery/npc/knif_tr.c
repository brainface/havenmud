#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

static void create() {
   npc::create();
   SetProperty("monasterynoleave",1);
   switch(random(2)){
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetKeyName("pierce trainee");
   SetShort("a pierce trainee");
   SetId( ({ "trainee","muezzin" }) );
   SetAdjectives( ({ "pierce","young" }) );
   SetLong("This young muezzin looks for " + possessive(this_object()) +
           " teacher, preparing to train more in the skills of the pierce "
           "weapons.  " + capitalize(nominative(this_object())) +
           " appears to be fairly proficient "
           "in those skills.");
   SetClass("valkyr");
   SetSkill("pierce attack",45);
   SetSkill("pierce defense",45);
   SetLevel(20+random(5));
   SetRace("muezzin");
   SetInventory( ([
                    M_OBJ + "knif_t" : "wield knife in left hand",
               ]) );
   SetMorality(450);
   SetCurrency("cuicui",3000);
}
