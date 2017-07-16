/* a horse for the mansion
   kyla 11-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("horse");
  SetShort("a black horse");
  SetLong("This large horse is obviously very well bred. The coloration "
        "is that of a midnight black, and the horse is obviously very strong.");
  SetGender("male");
  
  SetRace("horse");
  SetClass("animal");
  SetLevel(14);
  SetId( ({"horse"}) );
  SetAdjectives( ({"black", "large"}) );
  }
