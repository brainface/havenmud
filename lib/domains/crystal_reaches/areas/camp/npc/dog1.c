#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("dog");
  SetId( ({"dog"}) );
  SetAdjectives( ({"black", "large"}) );  
  SetShort("a large black dog");
  SetLong(
    "This large black dog looks friendly but "
    "ready to defend its owners and territory.  ");
  SetRace("dog");
  SetGender("male");
  SetClass("animal");
  SetLevel(3);
  
}
