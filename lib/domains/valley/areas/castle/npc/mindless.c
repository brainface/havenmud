#include <lib.h>
inherit LIB_SENTIENT;
#include "../castle.h"

static void create() {
   sentient::create();
   SetKeyName("mindless serf");
   SetShort("a mindless serf");
   SetId( ({ "serf","brute" }) );
   SetAdjectives( ({ "mindless","dumb" }) );
   SetLong("A dumb expression covers the brute's face as he looks around "
           "and attempts to comprehend the concept of breathing.");
   
   SetGender("male");
   SetRace("human");
   SetClass("rogue");
   SetLevel(10+random(3));
   SetAction(4, ({
                   "!emote frowns at his hands.",
                   "!emote looks confused.",
              }) );
   SetLimit(3); 
   SetWander(33+random(6));
   SetMorality(20);
}