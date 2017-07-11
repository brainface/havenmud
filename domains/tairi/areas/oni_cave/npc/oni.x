#include <lib.h>
#include <std.h>
inherit LIB_NPC;

static void create() 
  {
  npc::create();
  SetKeyName("oni");
  SetShort("a common oni");
  SetId( ({ "oni" }) );
  SetAdjectives( ({ "common" }) );
  SetRace("lizardman","oni");
  SetClass("rogue");
  SetLevel(4 + random(4) );
  SetGender("male");
  SetLong("This oni is about eight feet tall and appears to be very strong.  He "
    "has long talons on the end of his hands and feet and red skin.  His head has "
    "three bulging eyes, a large horn in the middle of his forehead, and long, "
    "black hair that drops down to his shoulders.");
  SetCurrency( ([
     "koken" : random(150),
     ]) );
  SetAction(3, ({
    "!mutter",
    "!growl",
    }) );
  SetCombatStyleLevel("ninjitsu", 20);
  SetCombatStyle("ninjitsu");
  }

