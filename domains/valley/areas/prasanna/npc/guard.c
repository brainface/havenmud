#include <lib.h>
#include <std.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("ethereal guardian");
   SetId( ({ "guard", "guardian" }) );
   SetAdjectives( ({ "ethereal" }) );
   SetFriends(({"ethereal guardian", "guardian", "guard"}));
   SetShort("an ethereal guardian");
   SetLong("This guardian is a remnant of the city's population, "
           "partially tangible, but existing mostly on another "
           "plane of existance. She looks alert and the gleam in her "
           "eyes hints at vast reserves of magical power. ");
  
   SetRace("elf");
   SetClass("necromancer");
   SetLevel(33);
   SetMorality(15);
   SetGender("female");
   SetCurrency("imperials",150);
   SetSpellBook( ([ 
      "fireball"  : 100, 
      "acid rain" : 100,
      "sphere"    : 100 ]) );
   SetAction(5, ({ 
                "The guardian looks around suspiciously." 
                }) ); 
   SetCombatAction(55, ({ 
      "!cast fireball",
      "!cast acid rain",  
      "!cast sphere" 
      }) ); 
   SetInventory( ([ 
      PR_OBJ +  "/sandals" : "wear sandals" ,
      PR_OBJ + "/ethcloak" : "wear cloak", 
      STD_POLE + "small_halberd" : "wield halberd",
      ]) );
}
