#include <lib.h>
#include <domains.h>
#include <std.h>
inherit LIB_NPC;


static void create() {
  ::create();
  SetKeyName("kobold scavenger");
  SetShort("a tiny kobold scavenger");
  SetId( ({ "kobold", "scavenger" }) );
  SetAdjectives( ({ "tiny", "kobold" }) );
  SetRace("kobold");
  SetGender("male");
  if (random(2)) SetGender("female");
  SetClass("rogue");
  SetLevel(5 + random(5));
  SetLong("This pitiful creature looks emaciated from hunger. "
    "It's difficult to tell how far from starvation this kobold "
    "really is, due to a thick winter coat of fur which is in "
    "turn covered by a soft layer of hoarfrost.");
  SetInventory( ([
    STD_WEAPON "knife/spade" : "wield spade",
    ]) );
  SetFirstCommands( ({
    "pirate",
  }) );
  SetAction(5, ({
    "!farm with spade",
    "!say You give food?",
    "!shiver",
    "!eat my first potato",
    }) );
}
