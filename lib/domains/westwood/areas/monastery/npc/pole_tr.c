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
   SetKeyName("pole trainee");
   SetShort("a pole trainee");
   SetId( ({ "trainee","muezzin" }) );
   SetAdjectives( ({ "pole","young" }) );
   SetLong("This young muezzin looks for " + possessive(this_object()) +
           " teacher, preparing to train more in the skills of the pole "
           "weapons.  " + capitalize(nominative(this_object())) +
           " appears to be fairly proficient "
           "in those skills.");
   SetRace("muezzin");
   SetClass("fighter");
   SetLevel(20+random(5));
   SetInventory( ([
           M_OBJ + "pole_t" : "wield pole in left hand",
            ]) );
   SetMorality(550);
}