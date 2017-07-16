// Island
// Aerelus

#include <lib.h>
#include "../island.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("monkey");
  SetShort("a happy monkey");
  SetId( ({ "monkey" }) );
  SetAdjectives( ({"happy"}) );
  SetLong(
    "This cute little monkey has a permanent grin on his face. He is small, "
    "covered with short brown fur. His long tail is the perfect tool for "
    "keeping his balance on tree branches. He looks weak and pathetic, but "
    "very agile."    
  );  
  SetRace("mammal");
  SetClass("animal");
  SetLevel(5);
  SetGender("male");
  SetAction(6, ({
    "!grin",
    "!dance",
    "!say Eep!",
  }) );  
 }