//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("ostrich");
  SetId( ({"bird", "ostrich"}) );
  SetAdjectives( ({"wild"}) );
  SetShort("a wild ostrich");
  SetRace("bird");
  SetClass("animal");
  SetLevel(15);
  SetGender("female");
  SetLong("This large wingless bird seems very strong.");
  SetAction(5, ({
    "!emote kicks the dust with one enormous foot.",
    "!emote rustles her short gray wings.",
  }) );
}

