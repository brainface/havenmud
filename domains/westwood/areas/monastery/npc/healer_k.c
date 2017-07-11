#include <lib.h>
inherit LIB_HEALER;
#include "../monastery.h"

static void create() {
   healer::create();
   SetTown("Soleil");
   SetProperty("monasterynoleave",1);
   SetKeyName("Kaleid");
   SetShort("Kaleid, a joyous healer");
   SetId( ({ "kaleid","healer" }) );
   SetAdjectives( ({ "joyous" }) );
   SetLong("Kaleid has soft fur and smiles very happily.  He looks "
           "as if he has been training in the arts of Eclat "
           "for a very long time.");
   SetReligion("Eclat","Eclat");
   SetRace("muezzin");
   SetClass("priest");
   SetSkill("melee combat", 1, 2);
   SetLevel(45);
   SetGender("male");
   SetLocalCurrency("cuicui");
   
   SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
   SetMorality(1000);
   SetFriends( ({ }) );
   SetSpellBook( ([
        	"sanctify" : 100,
        	"rejuvenation" : 100,
          ]) );

   SetCombatAction(15,({ 
        "!cast sanctify",
        "!cast rejuvenation",
        "!speak in Oiseau What are you "
        "doing, we are peaceful and .. and joyous!",
        }) );

   SetInventory( ([
          M_OBJ + "robe" : "wear robe",
          ]) );
   SetCurrency("cuicui", random(30) + 15);
}