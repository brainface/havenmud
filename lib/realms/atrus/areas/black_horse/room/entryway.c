/* Entryway.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

int PreExit();

static void create() {
  room::create();
  SetShort("entryway of the Black Horse Inn");
  SetClimate("indoors");
  SetListen("There are roudy sounds coming from within the inn.");
  SetSmell("The air smells of horse dung and stale ale.");
  SetDayLight(55);
  SetNightLight(25);
  SetExits( ([
    "north" : "hallway",
    ]) );
  AddExit("out", "horseyard", (: PreExit :) );
  SetDayLong(
         "Sunlight pours into the entryway from the propped open front door. "
         "A set of large beams support the walls of the inn, the walls are "
         "whitewashed. The floor is well packed dirt. A tightly layered plank "
         "thatching make up the ceiling. Brightly polished sconces are set "
         "in the beams of either side of the entryway. To the north is the "
         "main entrance to the Inn."
          );
  SetNightLong(
         "The entryway doors close and open at the slightest touch. "
         "The floor and ceiling do not reflect back any quantity "
         "of light and appear dark against the stark contrast of the walls. "
         "The whitewashed walls reflect the candles which burn brightly in "
         "their sconces which are set in dark beams of either side of the "
         "entryway. To the north is the main entrance to the Inn."
         );
  SetItems( ([
  "doors" : "Double doors swing freely and return to a closed position after use.",
  ({ "wall", "walls" }) : "The walls are well sanded plaster that has been white-"
            "washed to a bright sheen. The plaster shows signs of recent patching.",
  ({ "candles", "candle" }) : "Two small candles mount sconces on the walls of either "
            "side of the entryway.",
  ({ "sconce", "sconces" }) : "Large brass sconces hold candles on each wall. They are "
            "set into the wall with a round headed brass spike pounded into the beams.",
  ({ "beam", "beams" }) : "Heavy wooden beams construct the framework of the panelled "
            "entryway. They are set evenly apart and run from floor to ceiling.",
  ({ "ceiling", "up" }) : "Overlapping wooden planks make up the ceiling and in turn "
            "the roof of the entryway. They are tightly secured and tar smeared to "
            "prevent leaks and rot.",
  ({ "floor", "down", "ground" }) : "The floor of the entryway is densely packed dirt "
            "which has been worn to a smooth surface after years of minimally moist use. "
            "The floor shows signs of recent sweeping and feels as hard as stone.",
    ]) );
  SetItemAdjectives( ([
    "inn" : ({ "large", "white", "black" }),
    ]) );
  SetInventory( ([
  ]) );
}

int PreExit() {
  if (this_player()->id("bhi_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
 }
