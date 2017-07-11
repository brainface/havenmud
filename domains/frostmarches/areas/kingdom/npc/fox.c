
/* fox
   Elasandria 4/15/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("fox");
  SetShort("a wily fox");
  SetId( ({"fox"}) );
  SetAdjectives( ({"wily","large","sleek","wild","red"}) );
  SetLong("This red fox is quite large with a sleek, muscled build. It is "
         "obvious to see that he is wild and wary of intruders.");

  SetGender("male");
  SetRace("dog");
  SetClass("animal");
  SetLevel(5);
  SetAction(5,
         ({"!emote bristles and watches you with narrowed yellow eyes.",
         "The wily fox bristles and watches you with narrowed yellow eyes."})
         );
  SetInventory( ([
         ]) );
}
