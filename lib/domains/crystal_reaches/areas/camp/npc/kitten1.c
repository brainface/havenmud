
#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;
static void create(){
  npc::create();
  SetKeyName("kitten");
  SetId( ({"kitten"}) );
  SetAdjectives( ({ "grey", "curious", "playful" }) );
  SetShort("a kitten");
  SetLong(
    "The gray kitten looks curious and playful."
  );
  SetRace("cat");
  SetGender("female"); 
  SetClass("animal");
  SetLevel(1);
    
}
