#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("ethereal guardian");
   SetId( ({ "guard", "guardian" }) );
   SetAdjectives( ({ "ethereal" }) );
   SetShort("an ethereal guardian");
   SetRace("elf");
   SetGender("female");
   SetClass("necromancer");
   SetLevel(33);
   SetMorality(15);
   SetLong("This guardian is a remnant of the city's population, "
           "partially tangible, but existing mostly on another "
           "plane of existance. Her face is translucent, as is the "
           "rest of her visible skin. Her features are hard, as if she "
           "has seen her share of battle. She looks alert and the gleam "
           "in her eyes hints at vast reserves of magical power. ");
   SetCurrency("imperials",150);
   SetSpellBook( ([ "planar assault" : 75, 
                          "plane warp" : 60,
                          "wards of protection" : 100 ]) );
   SetAction(5, ({ "The guardian looks around suspiciously." }) ); 
   SetCombatAction(45, ({ "!cast wards of protection",
                         "!cast plane warp",  
                         "!cast planar assault" })); 
   SetInventory( ([ PR_OBJ +  "/sandals" : "wear sandals" ,
                             PR_OBJ + "/ethcloak" : "wear cloak"  ]) );
}
