
/* A faerie guard
   Elasandria 4/18/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("faerie guard");

  SetShort("a faerie guard");

  SetId( ({"guard","faerie","man"}) );
  SetAdjectives( ({"faerie","agile","wiry"}) );
  SetLong("This faerie guard is quite agile and wiry. His sense of balance "
         "is apparent judging from his stance as he surveys the clearing "
         "for any hint of danger.");
  SetGender("male");
  SetRace("faerie");
  SetClass("fighter");
  SetLevel(20);
  SetMorality(120);
  SetAction(5,
       ({"!emote narrows his eyes in your direction.",
       "The guard narrows his eyes in your direction."})
       );
  SetInventory( ([
       KINGDOM_OBJ + "oakstaff" : "wield oaken staff",
      ]) );
}
