#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("dog");
  SetClass("animal");
  SetRace("dog");
  SetShort("a large dog");
  SetId( ({ "dog" }) );
  SetAdjectives( ({ "large" }) );
  SetLong("This furry death machine is huge for its species.  It stands \n"
          "nearly four feet high at the shoulder and looks like it could \n"
          "defend its territory to the last.");
  SetGender("male");
  SetLevel(1);
  SetCombatAction(5, ({
                   "!snarl angrily",
                   "!growl hungrily",
                   "!snarl violently",
                   "The dog leaps back, and LUNGES into combat.",
                  }) );
  SetAction(5, ({ 
                "!snarl",
                "!howl",
                 }) );
  }
