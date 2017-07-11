#include <lib.h>
#include "../avb.h"

inherit LIB_SENTIENT;


static void create() {
   sentient::create();
   SetProperty("averath cave",1);
   SetKeyName("water beetle");
   SetShort("a large water beetle");
   SetId( ({ "beetle" }) );
   SetAdjectives( ({ "water" }) );
   SetLong("The water beetle is greenish in color and rather small."
           "It has a smooth oval body that is rather hairy. Its two "
           "hind legs are very oarlike. It has a pair of wings that "
           "are laying flat on its back almost making a shell for "
           "itself. Running along its abdomen are two large tubes "
           "that are fluctuating. ");
   SetRace("insect");
   SetGender("male");
   SetClass("animal");
   SetLevel(30);
   AddLimb("right wing","torso",3,({ }) );
   AddLimb("left wing","torso",3,({ }) );
   AddLimb("left tube","first segment",2,({ }) );
   AddLimb("second tube","first segment",2,({ }) );
}

