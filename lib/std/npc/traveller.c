/*  A wandering rogueish type with pole defense */
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("traveller");
  SetShort("a wandering traveller");
  SetId( ({ "traveller" }) );
  SetAdjectives( ({ "wandering" }) );
  SetRace("elf");
  SetClass("rogue");
  SetSkill("pole defense", 5, 1);
  SetLevel(10 + random(10) );
  SetGender("male");
  SetLong("This wandering elf seems to be fascinated by his "
          "surroundings. His demeanor suggests that he is quite "
          "capable of taking care of himself.");
  SetCurrency( ([
    "imperials" : random(300),
    "rupies"    : random(100),
    "rounds"    : random(80),
     ]) );
  SetInventory( ([
      STD_POLE + "staff" : "wield staff",
     ]) );
  SetAction(3, ({
    "!emote hums tunelessly.",
     "!hum",
     "!whistle",
  "!emote looks around at the world.",
   "!say A fine day for travelling, don't you think?",
    "!say On my way to Haven Town, I am.",
    }) );
  }
