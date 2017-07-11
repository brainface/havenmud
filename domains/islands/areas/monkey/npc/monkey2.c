// Island
// Aerelus

#include <lib.h>
#include "../island.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("monkey");
  SetShort("a cute monkey");
  SetId( ({ "monkey" }) );
  SetAdjectives( ({"cute"}) );
  SetLong(
    "At about two feet tall, this little monkey is extremely cute. She "
    "appears to be young by monkey standards, and playful. She is almost "
    "entirely covered with short brown fur, though some parts of her body "
    "are still a little bald."    
  );  
  SetRace("mammal");
  SetClass("animal");
  SetLevel(3);
  SetGender("female");
  SetAction(6, ({
    "!giggle",
    "!emote scratches her bottom, glances around the area with a guilty look, "
    "and sniffs her fingers.",
  }) );  
 }