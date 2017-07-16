/*  A magical forest plane of random directions */
#include <lib.h>
#include "../planes.h"
inherit LIB_ROOM;

#include "forest/forest.h"
void Setup(int, int);
private int XPosition, YPosition, counter;

varargs static void create(int x, int y) {
  string n, s, e, w, ne, se, sw, nw;
  room::create();
  XPosition = x;
  YPosition = y;
  SetProperty("lower plane", 1);
  SetProperty("no teleport", 1);
  SetDayLight(-15);
  SetNightLight(-15);
  SetClimate("temperate");
  SetShort("in a twisting forest");
  SetProperty("no weather", 1);
  if (!random(2)) {
      n = FOREST_PLANE + (x) + "," + (y+1);
   }
  if (!random(2)) {
      s = FOREST_PLANE + (x) + "," + (y-1);
   }
  if (!random(2)) {
      e = FOREST_PLANE + (x+1) + "," + (y);
   }
  if (!random(2)) {
      w = FOREST_PLANE + (x-1) + "," + (y);
   }
  if (!random(2)) {
    ne = FOREST_PLANE + (x+1) + "," + (y+1);
   }
  if (!random(2)) {
    se = FOREST_PLANE + (x+1) + "," + (y-1);
   }
  if (!random(2)) {
    sw = FOREST_PLANE + (x-1) + "," + (y-1);
   }
  if (!random(2)) {
    nw = FOREST_PLANE + (x-1) + "," + (y+1);
   }
  if (ne) AddExit("northeast", ne);
  if (se) AddExit("southeast", se);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (!sizeof(GetExits())) AddExit("south", FOREST_PLANE + (x) + "," + (y-1));
  Setup(x, y);
  counter = 0;
 }

void Setup(int x, int y) {
  string long;
  string tmp;
  int n;
  long = "";
  for(n = 1;n <6;n++) {
  tmp = Longs[random(sizeof(Longs))];
  Longs -= ({ tmp });
  long += (tmp + " ");
  }

  if (y) {
  if (y > 0) tmp = "south";
    else tmp = "north";
   } else tmp = "";
  if (x) {
  if (x > 0) tmp += "west";
   else tmp += "east";
   }
  if (tmp != "") 
  long += "A bright greenish-yellow 'sun' hangs in the sky to the " + tmp + ".";


  SetLong(long);
  SetSmell( ([
      "default" : Smells[random(sizeof(Smells))],
    ]) );
  SetListen( ([
    "default" : Listens[random(sizeof(Listens))],
    ]) );
  foreach(string thing, int chance in NPCs) {
    if (!random(chance)) AddInventory(thing, 1);
  }
  foreach(string thing, int chance in Objects) {
    if (!random(chance)) AddInventory(thing, 1);
    }
  }
void heart_beat() {
	::heart_beat();
  foreach (object o in deep_inventory(this_object())) {
    if (userp(o)) return;
  }
  counter++;
  if (counter > 3)
    eventDestruct();
}
