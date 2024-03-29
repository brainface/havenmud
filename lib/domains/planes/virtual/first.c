/*  The first lower plane.
 *  Not sure exactly what I will call it just yet.
 */
#include <lib.h>
#include "../planes.h"
#define WHAT_PLANE "first"
inherit LIB_ROOM;
#include "first/first.h"
void Setup();
private int XPosition, YPosition, counter;

varargs static void create(int x, int y) {
  room::create();
  XPosition = x;
  YPosition = y;
  SetShort("in the first lower plane");
  SetProperty("no weather", 1);
  SetProperty("lower plane",1);
  SetProperty("no teleport", 1);
  SetClimate("arid");
  AddExit("north", FIRST_PLANE + x + "," + (y + 1) );
  AddExit("south", FIRST_PLANE + x + "," + (y - 1) );
  AddExit("west", FIRST_PLANE + (x - 1) + "," + (y) );
  AddExit("east", FIRST_PLANE + (x + 1) + "," + (y) );
  Setup();
  counter = 0;
  }

void Setup() {
   string long = "";
   string tmp;
   int x;

  for(x = 1;x < 6;x++) {
    tmp = Longs[random(sizeof(Longs))];
   Longs -= ({ tmp });
    long += (tmp + " ");
    }
  if (YPosition) {
  if (YPosition > 0) tmp = "south";
    else tmp = "north";
   } else tmp = "";
  if (XPosition) {
  if (XPosition > 0) tmp += "west";
   else tmp += "east";
   }
  if (tmp != "") 
  long += "There is a large castle to the " + tmp + ".";
  SetSmell( ([
     "default" : Smells[random(sizeof(Smells))],
    ]) );
  SetItems( ([
     "castle" : "The castle looms as the primary feature of the land.",
     ]) );
  if (XPosition == 0 && YPosition == 0) {
    long += "There is a large castle here towering over the land.";
     AddEnter("castle", PLANE_CASTLE + WHAT_PLANE + "/entrance");
    }
  SetLong(long);
  if (!random( 5)) AddInventory(PLANE_NPC + "lemure", random(5)+1);
  if (!random(10)) AddInventory(PLANE_NPC + "bane", random(3));
  if (!random(10)) AddInventory(PLANE_NPC + "barbed", random(3));
  if (!random(20)) AddInventory(PLANE_NPC + "planeswalker",1);
  if (!random(20)) AddInventory(PLANE_NPC + "maralith", random(3));
  if (!random(20)) AddInventory(PLANE_NPC + "pf", 1);
  }

/*  This is to stop a massive issue. Massive. */

void heart_beat() {
	::heart_beat();
  foreach (object o in deep_inventory(this_object())) {
    if (userp(o)) return;
  }
  counter++;
  if (counter > 3)
    eventDestruct();
}
