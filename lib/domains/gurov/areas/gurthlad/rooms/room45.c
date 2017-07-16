#include <lib.h>
#include <domains.h>
#include "../gurthlad.h"
inherit LIB_ROOM;
int DomainCheck();

static void create() {
  room::create();
  
  SetShort("the Plains of Gurthlad near the River Bjorn");
  SetLong(
    "The plains of Gurthlad end here at the River Bjorn, which seperates the "
    "lands traditionally seen as the Principality of Gurov from the Yozrath "
    "Desert. To the south lies a shallow ford which allows the river to be "
    "crossed. The grass lies dead and brown even this close to water. Small "
    "tubers seem to be the only vegetation hardy enough to grow here."
    );
  SetExits( ([    
    "east"  : G_ROOMS "/room46",
    ]) );
  AddExit("south", YOZRATH_VIRTUAL "desert/40,100", (: DomainCheck :) );
  SetSmell( ([
          "default" : "A light wind brings the faint smell of death."]) );
  SetItems( ([
          ({ "grass", "dead grass" }) : "Blades of withered dead grass.",
          "dirt" : "Dry, dusty, lifeless, gray dirt.",
          ({ "plain", "land" }) : "A dusty brown plain. Nothing can be "
          "seen but dead grass and dirt rolling away over the horizon.",
          ({ "tuber", "tubers", "plant", "plants" }) : "These brown, red "
          "leafed, tubers are all around. These plants are the squealers "
          "primary food."]) );
  SetInventory( ([ G_NPC + "/squealer.c" : 3 ]) );
  }

int DomainCheck() {
  if (!OPEN_YOZRATH)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_YOZRATH;  
}