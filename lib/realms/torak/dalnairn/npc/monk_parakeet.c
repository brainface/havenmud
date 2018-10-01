// Torak@Haven 2017

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_NPC;

static void create() {

  ::create();
  SetKeyName("parakeet");
  SetId( ({ "monk", "parakeet" }) );
  SetAdjectives( ({ "green" }) );
  SetShort("a green parakeet");
  SetLong(
    "The upperparts of this parakeet are bright green. The forehead "
    "and breast are a pale grey with darker scalloping blending into "
    "a yellow underpants. The remiges are dark blue, and "
    "the tail is long and tapering. It has a bright orange bill."
    );
  SetRace("bird");
  SetClass("animal");
  SetLevel(5 + random(3));
  SetAction(12 + random(4), ({
    "!emote calls out a loud and throaty, '%^CYAN%^BOLD%^chape-yee!%^RESET%^'",
    "!emote calls out, '%^CYAN%^BOLD%^quak quak quak-wi quarr.%^RESET%^'",
    "!emote sceaches out a loud and shrill, '%^CYAN%^BOLD%^skveet!%^RESET%^'",
    "!nog nog",
  }) );
  if(random(2)) { 
    SetGender("male");
  } else  {
    SetGender("female");
  }
  SetCorpseItems( ([
    DAL_OBJ + "green_feather" : 1+random(3),
  ]) );
  SetLimit(15);
  SetProperty("dalnoleave", 1);
  SetProperty("forestnoleave", 1);
//  SetWander(5 + random(3));
}
