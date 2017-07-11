//Illura@haven
//Nov 2010
#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../oil.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("pensive goblin boss");
  SetShort("a pensive goblin boss");
  SetId( ({ "goblin", "boss" }) );
  SetAdjectives( ({ "pensive", "goblin" }) );
  SetRace("goblin");
  SetBaseLanguage("Gobyshkin");
  SetClass("fighter");
  SetLevel(70);
  SetLong(
    "He hasn't been the boss long, but the wrinkles in this goblin's forehead "
    "are very thick from all the thinking he does about numbers. His "
    "gnarled hands are arthritic from all the counting he does on his "
    "fingers, and his little beard has all but fallen out from all the "
    "stroking he's given it in the past few weeks."
    );
  SetGender("male");
  SetInventory( ([
    OIL_OBJ "rod" : "wield rod",
    OIL_OBJ "hat2" : "wear hat",
    ]) );
  SetCurrency("rounds", random(300));
  SetAction(20, ({
    "!say Carry the two, add the three...oh, shoot.",
    "!say You wouldn't know anything about subtraction, would you?",
    "!say I'm so going to be fired.",
    "!emote laments worriedly.",
    "!emote cries over paperwork."
  }) );
  SetCombatAction(20, ({
    "!say Get out of my office!"
    "!say Get back to work!",
    "!say You're going to mess up my papers!"
    }) );
    
}
