#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;	

static void create() {
  npc::create();
  SetKeyName("dancer");
  SetShort("a graceful dancer");
  SetLong("The graceful dancer has long, thick black "
       "hair and violet eyes.  She flashes her beautiful smile "
       "as she twirls about and sings beautifully.");
  SetId( ({ "dancer"}) );
  SetAdjectives(  ({"graceful"}) );
  SetRace("human");
  SetClass("bard");
  SetLevel(20);
  SetGender("female");
  SetMorality(200);
  SetAction(5, ({ "The dancer sways and twirls gracefully.",
                       "The dancer sings beautifully. "}));
  SetInventory( ([C_OBJ + "dress1" : "wear dress",
                  C_OBJ + "dagger1" : "wield second dagger",
                  C_OBJ + "dagger1" : "wield first dagger",
  ]) );
call_out( (: eventForce, "wield first dagger" :), 0);
call_out( (: eventForce, "wield second dagger" :), 0);
}
