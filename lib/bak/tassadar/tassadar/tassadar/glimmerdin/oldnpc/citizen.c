/*  a dwarf who walks and talks */

#include <lib.h>
#include "../glim.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("dwarf");
  SetShort("a dwarven citizen");
  SetReligion("Kylin", "Kylin");
  SetProperty("glimcitizen", 1);
  SetId( ({ "dwarf", "citizen", "town_wander", "glim_wander" }) );
  SetAdjectives( ({ "strong", "buff" }) );
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(random(15)+2);
  SetLong("This is one of dwarves of Glimmerdin.  "
    "His beard is white and thickly braided, and he seems immensly "
    "strong."); 
  SetGender("male");
  SetFriends( ({"tembeg", "rancor", "raal", "rallor", 
    "tabitha", "dwarf", "civak", "guard", "patrol", 
    "samik", "gracchus", "eredos", "dorscha", "bralor"}) );
  SetCurrency("nuggets", random(8));
  SetAction(4, ({
      "!speak Halflings still live in the hills around Glimmerdin.",
      "!speak Rancor made my son a great axe the other day.",
      "!speak We should storm the lizardmen's new stronghold "
      "and slay them all!",
      "!speak War is the hammer that shapes the world!",
      }) );
  SetWander(4);
  SetMorality(200);
  SetTalkResponses( ([
    ({ "armory", "weapony", "weapon", "armor" }) : 
       "Finest equipment in all of Kailie! Down the "
       "Western Passage.",
    ({ "elf", "elves" }) : 
       "They are now our allies under Kylin",
  ]) );
}
