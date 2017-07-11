
/* stag
   Elasandria 4/18/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("white stag");
  SetShort("a white stag");
  SetId( ({"stag"}) );
  SetAdjectives( ({"white","enchanted"}) );
  SetLong("This majestic white stag is fleet and graceful. Its glowing red "
      "eyes cautiously survey its surroundings. It is rumored that the beast "
      "is actually a faerie in disguise and is, therefore, a grand prize for "
      "hunters everywhere.");
  SetGender("male");
  SetRace("deer");
  SetClass("animal");
  SetLevel(20);
  SetAction(5,
        ({"!emote appears ready to bolt to safety at any moment.",
         "The white stag appears ready to bolt to safety at any moment."
         }) );
  SetInventory( ([
        ]) );
}
