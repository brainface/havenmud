//Illura@haven
//Nov 2010
//Ship Captain
#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../oil.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("ship captain");
  SetShort("ship captain");
  SetId( ({ "captain" }) );
  SetAdjectives( ({ "ship" }) );
  SetRace("goden");
  SetTown("Keryth");
  SetClass("rogue");
  SetClass("sailor");
  SetLevel(70);
  SetLong(
    "This ship captain has wasted away, unable to get her ship "
    "back in sailable waters or save her crew from starvation "
    "and disease. Her golden eyes are filmy with unshed tears "
    "and her muzzle is weathered and gray. She is stubborn "
    "enough to put up a pitiful, yet valiant last fight."
    );
  SetGender("female");
  SetInventory( ([
    OIL_OBJ "sword" : "wield sword",
    OIL_OBJ "hat" : "wear hat",
    OIL_OBJ "boots" : "wear boots",
    ]) );
  SetAction(20, ({
    "!emote whistles an off tune sea shanty.",
    "!say I just don't know what happened.",
    "!emote looks at you with tired eyes."
  }) );
  SetCurrency("senones", random(1000));
  SetCombatAction(20, ({
    "!say Avast!",
    "!say I give no quarter to pirates!",
    "!say Get your scurvy tail off my ship!"
    }) );
    
}
