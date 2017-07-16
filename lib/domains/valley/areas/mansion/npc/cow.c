/* a cow for the mansion
  kyla 11-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("cow");
  SetShort("a brown cow");
  SetLong("This is a very large brown cow. She has very large brown eyes "
          "and a long tail.");
  SetId( ({"cow"}) );
  SetAdjectives( ({"brown", "large"}) );
  SetGender("female");
  SetRace("cow");
  SetClass("animal");
  SetLevel(10);
  SetAction(5, "The cow chews loudly on some grass.");
  }
