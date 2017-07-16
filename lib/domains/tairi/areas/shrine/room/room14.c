
#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;
string PlotSearch();

static void create() {
  room::create();
  SetShort("an unkempt plot of land");
  SetLong("The marble outer wall of the shrine"
          " can be seen far to the northwest. The fog"
          " here is very intense and makes it not"
          " only hard to see but also hard to breathe."
          " There are many small wooden markers scattered"
          " throughout the area. There is a path that"
          " leads west towards the shrine, otherwise"
          " there is not much to see here.");
  SetItems( ([
          ({ "path", "stone", "stones", "weeds"}) :
          "The path here has seemingly been neglected"
          " and shows signs of aging. The stones that"
          " were once neatly arranged to border the"
          " path are broken or missing and weeds"
          " sprout in random spots along the path.",
          ({ "fog" }) :
          "The fog here is very thick and unnatural.",
          ({ "shrine", "arch" }) :
          "The shrine is hard to see from this far away.",
          ({ "marker", "markers" }) :
          "These small wooden markers look like a mixture"
          " of grave markers and protection charms."
          ]) );
  SetItemAdjectives( ([
          "path" : ({ "broken", "neglected" }),
          "fog" : ({ "unnatural", "thick" }),
          "shrine" : ({ "small", "modest" }),
          "marker" : ({ "small", "wooden", "wood" }),
          ]) );                 
  SetSmell( ([
          "default" : "The coarse smell of death arrives from the south.",
          ]) );
  SetListen( ([
          "default" : "The sound of distant moaning"
                      " reaches here.",
          ]) );
  SetExits( ([
           "west" : SHRINE_ROOM "room10",
          ]) );
  SetInventory( ([
           SHRINE_NPC "ghost3" : 3,
          ]) );
  SetSearch( ([
          "default" : (: PlotSearch :),
         ]) );
}

string PlotSearch() {
  if (GetExit("south")) {
    return "There is nothing else to find.";
    }
  AddExit("south", SHRINE_ROOM "room15");
  return "You find a way through the brush to the south!";
  }
