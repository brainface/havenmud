// A rat, proposed by Mahkefel
// Urien@Haven 14JUN2023

#include <lib.h>
#include <std.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("rat");
  SetId( ({ "rat", "rodent"}) );
  SetAdjectives( ({ "wet" }) );
  SetRace("rodent","rat");
  SetClass("animal");
  SetGender("male");
  SetLevel(random(8) + 2);
  SetShort("a wet rat");
  SetLong("This burnt umber coloured rat is soaked from head to "
          "tail. It has several black whiskers under and above "
          "his triangle peach nose. Two yellowed teeth protrude "
          "from the black lips of the rat show some age and "
          "much use. It doesnt seem completely malnourished "
          "but it does seem to be seeking out more sources "
          "of easily accessable food nearby.");
  SetAction(2, ({
     "Rat chews something slowly from inside his cheeks.",
     "The rat looks hesitant to move about freely.",
     "A rat moves place to place in a quiet and smooth stride."
     }) );
}
