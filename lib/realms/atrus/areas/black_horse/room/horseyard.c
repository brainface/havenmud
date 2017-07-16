/* Horseyard.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside the Black Horse Inn");
  SetClimate("temperate");
  SetExits( ([
    "west" : "/realms/atrus/workroom.c",
    ]) );
  SetDayLong(
         "The horseyard of the Black Horse Inn is well kept. Large gardens line "
         "both sides of the yard. New dried pine wood chips make a soft surface "
         "for horses' travel beaten hooves. Fresh oats are hung in feed bags off "
         "the cinch poles. "
         "Large iron lanterns, blued from over heating, hang from each "
         "pillar on the front of the inn. A long porch lines the front "
         "of the building. The inn itself is whitewashed logs with "
         "black trim. The second floor windows and black shutters are "
         "open allowing the drapes inside to flow in the breeze. A large "
         "awning stretches out into the yard in case of rain."
          );
  SetNightLong(
         "The horseyard of the Black Horse Inn is well kept. Large gardens line "
         "both sides of the yard. New dried pine wood chips make a soft surface "
         "for horses' travel beaten hooves. Fresh oats are hung in feed bags off "
         "the cinch poles."
         "Large lanterns light up the porch that stretches along the front "
         "of the inn. The second floor windows are closed and shuttered against "
         "any weather. Slim lines of light shine through the closed shutters. "
         "small candle-holding lanterns have been hung from a long awning that "
         "runs from the door to the yard in case of bad weather."
         );
  SetItems( ([
  "inn" : "The large white, black trimmed inn stands stark against the green "
          "backdrop of the woods around it. Windows line the second floor while "
          "a few small windows adorn the first. Above the second floor is a "
          "highly pitched roof that reaches nearly another two stories above the "
          "second floor.",
  "yard" : (: GetLong :),
  ({ "torches", "torch" }) : "Five large lanterns are tied to the pillars that support "
          "overhanging eaving on the front of the inn.",
    ]) );
  SetItemAdjectives( ([
    "inn" : ({ "large", "white", "black" }),
    ]) );
  SetInventory( ([
  ]) );
  SetEnters( ([
    "inn" : BHI_ROOM "entryway",
  ]) );
 }
