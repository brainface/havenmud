/*coded by AtRuS 07-11-99*/
// Updated by Zeratul

#include "../lake.h"
#include <lib.h>

inherit LIB_NPC; 
 static void create() { 
  npc::create(); 
  SetKeyName("clara");
   SetId( ({ "clara","chef" }) );
  SetShort("Clara the wife");
   SetAdjectives( ({ "wife" }) );
   SetLong("This wonderful chef looks as if she spends every hour "
          "at the stove cooking fish. She is quiet but she "
          "looks quite capable of taking care of hemself.");
   SetRace("human"); 
   SetClass("fighter"); 
   SetLevel(10);
   SetGender("female"); 
   SetMorality(100);
   SetAction(5, ({ 
       "!whistle", 
       "!say oh how I love to cook fish!", 
       "!emote cleaves a fish in half effortlessly.",
       "!say I need a new cleaver, this one is dulling.", }) ); 
   SetCombatAction(15, ({ 
       "!say you better get outta here!", 
       "!say my husband will be upset with you!", }) ); 
    SetDie("Clara freezes solid as she falls onto the floor" );
    SetInventory( ([
     LAKE_OBJ + "/cabinkey" : 1,
     LAKE_OBJ + "/cleaver" : "wield cleaver",
     LAKE_OBJ + "/fish_1_meal" : 2,
     ]) );
    
  }
