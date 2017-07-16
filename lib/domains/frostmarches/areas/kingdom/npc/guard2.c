
/* a faerie guard
   Elasandria 4/18/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("faerie guard");
  SetShort("a faerie guard");
  SetId( ({"guard","faerie","soldier","man"}) );
  SetAdjectives( ({"faerie","wiry","slight"}) );
  SetRace("faerie");
  SetLong("This faerie has the clearly defined muscles of a soldier who "
         "gets regular exercise using his gleaming longsword. His stature "
         "is rather large for his race, which he clearly uses to his full "
         "advantage.");
  SetGender("male");
  SetClass("fighter");
  SetLevel(20);
  SetMorality(-75);
  SetAction(5,
       ({"!emote casts dark glances in your direction.",
       "The guard casts dark glances in your direction."})
       );
  SetInventory( ([
       KINGDOM_OBJ + "longsword" : "wield longsword",
       ]) );
}
