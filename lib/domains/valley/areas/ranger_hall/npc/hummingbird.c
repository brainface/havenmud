#include <lib.h>
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetKeyName("sparkling hummingbird");
   SetShort("a sparkling hummingbird");
   SetId( ({ "bird" }) );
   SetAdjectives( ({ "sparkling" }) );
   SetLong("The emerald hummingbird sparkles in the light, whisking "
           "here and there in search of food. Its wings are a rapid "
           "blur that make a whirring sound.");
   SetRace("bird");
   SetGender("female");
   SetClass("animal");
   SetLevel(1+random(1));
   SetMorality(-5);
   AddCaffeine(30);
   SetStat("agility",10,2);
   SetCombatAction( random(15), ({ 
   		"!emote dives at your face!" 
   		}) );
   SetAction(random(2), ({ 
   		"!emote buzzes through the forest looking for nectar.",
      "!emote buzzes around your head, chirping angrily!",
      "!emote settles briefly on a branch." 
      }) );
   SetDie("The hummingbird flops to the ground, dead.");
}
