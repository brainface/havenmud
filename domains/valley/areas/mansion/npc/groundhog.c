// groundhog for meadow 
// Kyla 9-29-97
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("groundhog");
  SetShort("a furry groundhog");
  SetId( ({ "groundhog", "rodent" }) );
  SetAdjectives( ({ "furry", "chubby" }) );
  
  SetRace("rodent");
  SetClass("animal");
  SetGender("male");
  SetLevel(1);
  SetLong("A chubby rodent with big teeth looks harmless.");
}
