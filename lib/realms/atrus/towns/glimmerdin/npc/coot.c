/*  some old coot who walks around */

#include <lib.h>
#include "../glim.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("dwarf");
  SetShort("an old dwarf");
  SetId( ({ "dwarf", "town_wander",  }) );
  SetAdjectives( ({ "old" }) );
  SetRace("dwarf");
  SetClass("fighter");
  SetStat("durability", 10, 4);
  SetLevel(random(10)+2);
  SetLong("This is one of the older dwarven citizens of Glimmerdin.  "
    "He carries himself with air of pride for his city and for the " 
    "dwarven race on the whole.");
  SetGender("male");
  SetCurrency("glims", random(10));
  SetAction(6, ({
      "!speak I have heard that some halflings still live in seclusion "
        "within the mountains.",
      "!speak I will have to see Tembeg about some armor.",
      "!speak The primitives should think twive before rising "
        "in malice against the dwarves!",
      "!speak Elves can be so annoying...",
      }) );
  SetWander(5);
  SetLimit(1);
  SetMorality(400);
  SetTalkResponses( ([
    ({ "armory", "weapony", "weapon", "armor" }) : 
       "Finest equipment in all of Kailie! On the "
       "Upper Level of town.",
    ({ "elf", "elves" }) : 
       "Back in the day we did not honor them with "
       "mention in our grand town of stone!",
  ]) );
}
