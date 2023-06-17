// A rat, proposed by Mahkefel
// Making this a random gender. male or female.
// Kudos to Mahkefel for the help 
// Urien@Haven 16JUN2023

#include <lib.h>
#include <std.h>
#include "./includes.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("rat");
  SetId( ({ "rat", "rodent"}) );
  SetAdjectives( ({ "wet" }) );
  SetRace("rodent","rat");
  SetClass("animal");
  SetGender(GetRandomGender());
  SetLevel(random(8) + 2);
  SetShort("a wet rat");
  SetLong("This burnt umber coloured rodent is soaked from head to "
          "tail. It has several black whiskers under and above "
          "a small triangle peach nose. Two yellowed teeth protrude "
          "from the black lips of the rat, it shows some age and "
          "much useage. It doesnt seem completely malnourished "
          "but it does seem to be seeking out more sources "
          "of easily accessable food nearby with both beady black "
          "eyes. ");
  SetAction(2, ({
     "Rat chews something slowly from the ground.",
     "The rat looks hesitant to move about freely.",
     "A rat moves place to place in a quiet and smooth stride."
     }) );
}
