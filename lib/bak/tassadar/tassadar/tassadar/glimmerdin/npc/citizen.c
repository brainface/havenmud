/*  a dwarf who walks and talks */

#include <lib.h>
#include "../glim.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("dwarf");
  SetShort("a dwarven citizen");
  SetReligion("Kylin", "Kylin");
  SetId( ({ "dwarf", "citizen", "town_wander", }) );
  SetAdjectives( ({ "dwarven" }) );
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(random(15)+2);
  SetLong("This is one of dwarves of Glimmerdin.  "
    "His beard is white and thickly braided, and he seems immensly "
    "strong."); 
  SetGender("male");
  SetCurrency("glims", random(8));
  SetAction(4, ({
      "!speak Orcs still live in the tunnels under Glimmerdin.",
      "!speak Rancor made my son a great axe the other day.",
      "!speak We should storm the orcs' stronghold "
      "and slay them all!",
      "!speak War is the hammer that shapes the world!",
      }) );
  SetWander(4);
  SetMorality(200);
  SetTalkResponses( ([
    ({ "orc", "orcs" }) : 
       "They hide like vermin in the tunnels under the town.",
  ]) );
}
