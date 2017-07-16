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
   SetKeyName("sparring partner");
   SetShort("a sparring partner");
   SetId( ({ "trainee","muezzin","partner" }) );
   SetAdjectives( ({ "pole","young","sparring" }) );
   SetLong("This young muezzin looks for " + possessive(this_object()) +
           " teacher, preparing to train more in the skills of the pole "
           "weapons.  " + capitalize(nominative(this_object())) +
           " appears to be fairly proficient "
           "in those skills.");
   SetRace("muezzin");
   SetClass("fighter");
   SetLevel(20 + random(10));
   
   SetInventory( ([
           M_OBJ + "pole_t" : "wield pole in left hand",
           ]) );
   SetMorality(550);
   SetAction(5,({ "!say I'm looking for help with my pole combat.  Is there anyone around who could "
                "spar with me?  Maybe someone that could protect me with magic "
                "while we train?","!say I'm hoping to get a chance to practice my pole combat.  "
                "Is there anyone around who could help me?  Maybe someone who could protect me with magic?",
                "!say I wish I could find someone to help me out with melee combat.  It would be amazing "
                "if a druid came by; I love it when they protect me with magic.  No one gets hurt!" }) );
}
