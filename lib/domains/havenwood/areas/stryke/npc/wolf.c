/*  A wolf for the lair entrance. */
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("wolf");
  SetEncounter(100);
  SetClass("animal");
  SetRace("dog");
  SetLevel(random(8) + 3);
  SetShort("a large wolf");
  SetGender("female");
  SetId( ({ "wolf" }) );
  SetAdjectives( ({ "large" }) );
  SetLong("This huge and furry death machine has a look to her "
          "that could scare even the most hardened of warriors.  Her "
          "fur is roughly matted with the blood and fluids of her "
          "former meals.");
  SetAction(5, 
       ({ "!growl hungrily",
          "!sniff eagerly",
          "!howl wildly",
          "!snarl evilly", 
          "!glare visciously",
         }) );
  }
