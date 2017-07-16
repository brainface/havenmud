/* a baby deer
    kyla 11-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("baby deer");
  SetShort("a baby deer");
  SetLong("This spotted deer is quite small and has obviously not been "
          "walking for very long. It stands on wobbly legs.");
  SetId( ({"baby", "deer"}) );
  SetAdjectives( ({"baby", "small"}) );
  SetMorality(300);
  SetGender("male");
  SetRace("deer");
  SetClass("animal");
  SetLevel(2);
  SetAction(7, "The small deer looks at you with innocent eyes.");
  }
