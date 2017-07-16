#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("dog");
  SetId( ({"dog"}) );
  SetAdjectives( ({"yellow", "large"}) );
  SetShort("a large yellow dog");
  SetLong(
    "This large yellow dog looks like it has "
    "been bred to defend. It has a large head and "
    "a deep, muscular chest. Its jaws are very "
    "strong."
    );
  SetRace("dog");
  SetGender("male");
  SetClass("animal");
  SetLevel(5);
  
}
