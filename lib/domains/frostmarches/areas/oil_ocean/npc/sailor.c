//Illura@haven
//Nov 2010
//Dying Sailor
#include <lib.h>
#include <domains.h>
#include "../oil.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("a dying sailor");
  SetShort("a dying sailor");
  SetId( ({ "sailor" }) );
  SetAdjectives( ({ "dying", "a"}));
  SetRace("goden");
  SetTown("Keryth");
  SetClass("viking");
  SetLevel(60);
  SetLong(
    "This sailor, like his fellows, is dying of starvation or disease or "
    "both. The fur hangs in folds and hollows along his bones, and "
    "his golden eyes are cloudy. He looks like he is not long for "
    "this world."
    );
  SetGender("male");
  SetInventory( ([
    OIL_OBJ "sword" : "wield sword",
    OIL_OBJ "boots" : "wear boots",
    ]) );
  SetCurrency("senones", random(1000));
  SetAction(20, ({
    "!cough",
    "!say We ran aground, and now we'll never get home.",
    "!emote groans and shuffles aimlessly about the hold."
  }) );
  SetCombatAction(20, ({
    "!say Help me, mates!",
    "!say Can't you see we've had enough?",
    }) );
    
}
