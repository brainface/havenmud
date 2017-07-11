/* an annoying seagull
   kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("seagull");
  SetShort("seagull");
  SetId( ({"seagull", "bird"}) );
  SetAdjectives( ({"white", "large"}) );
  SetGender("male");
  SetRace("bird");
  SetStat("durability", 5,5);
  SetClass("animal");
  SetLevel(2);
  SetLong("This large bird is quite fat and looks to be quite able to take "
          "care of itself.");
  SetAction(5, ({ "!squaks loudly" }) );
  }
