#include <lib.h>
#include <domains.h>
#include "../rome.h"
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("gnaeus");
  SetShort("Gnaeus Aurelis, Explorator of Santum");
  SetId( ({ "gnaeus", "explorator", "gnaeus aurelis", "aurelis" }) );
  SetAdjectives( ({ "gnaeus", "gnaeus aurelis", "of sanctum",
  	                "explorator", }) );
  SetRace("human");
  SetClass("rogue");
  SetLevel(25);
  SetGender("male");
  SetTown("Sanctum");
  SetBaseLanguage("Imperial");
  SetLong("Gnaeus Aurelis is a scout of the Sanctum Legion. "
          "General Marcus ordered Gnaeus to out into the land "
          "of Kailie and explore.  A few years later, Gnaeus "
          "returned and help all in Sanctum that require his "
          "talent. If you are brave enough, <ask gnaeus for "
          "quest>.");
  SetMorality(100);
  SetInventory( ([
    ]) );
  	
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}


