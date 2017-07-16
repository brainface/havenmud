/* a young girl for the mansion
   kyla 5-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("young girl");
  SetShort("a young girl");
  SetId( ({"girl"}) );
  SetAdjectives( ({"young"}) );
  SetLong("This young girl can't be more than twelve or thirteen years "
         "old, but carries herself as if she were twenty. Her beautiful "
         "blonde curls hang to the middle of her back.");
  SetRace("human");
  SetGender("female");
  SetClass("rogue");
  SetLevel(8);
  SetMorality(-75);
  SetAction(6,
       ({"!emote pout"}) );
  SetInventory( ([
          ]) );
  }
