/* a white tailed deer
  kyla 11-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("deer");
  SetShort("a white-tailed deer");
  SetId( ({"deer"}) );
  SetAdjectives( ({"white", "whitetailed", "white-tailed"}) );
  SetLong("This white-tailed deer is average size and appears quite "
          "soft. She seems a bit plump for this time of year.");
  SetRace("deer");
  SetClass("animal");
  SetLevel(8);
  SetGender("female");
  SetAction(7, "The deer looks at you with wide, frightened eyes.");
  }
