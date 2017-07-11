/* a hummingbird
   KYla 11-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("hummingbird");
  SetShort("a small hummingbird");
  SetLong("This is very small bird with a long beak. "
          "The bird is very colorful.");
  SetId( ({"bird", "hummingbird"}) );
  SetAdjectives( ({"small"}) );
  SetGender("male");
  
  SetRace("bird");
  SetClass("animal");
  SetLevel(2);
  SetAction(7, "The small bird flitters about happily.");
  }
