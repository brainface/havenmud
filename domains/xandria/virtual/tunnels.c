/*  A magical forest plane of random directions */
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

#include "tunnels/tunnels.h"
void Setup(int, int);
private int XPosition, YPosition, counter;

varargs static void create(int x, int y) {
  string n, s, e, w, ne, se, sw, nw, u;
  object boarder;
  int yes;
  room::create();
  XPosition = x;
  YPosition = y;
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("in a twisting series of tunnels");
 
  boarder = find_object(XANDRIA_VIRTUAL "tunnels/" + x + "," + (y + 1));
  if (boarder) 
    if (boarder->GetExit("south")) yes = 1;
  boarder = 0;
  if (!random(4) || yes) {
      n = TUNNELS_ROOM + (x) + "," + (y+1);
   }
  yes = 0;
  boarder = find_object(XANDRIA_VIRTUAL "tunnels/" + x + "," + (y - 1));
  if (boarder) 
    if (boarder->GetExit("north")) yes = 1;
  boarder = 0;
  if (!random(4)  || yes) {
      s = TUNNELS_ROOM + (x) + "," + (y-1);
   }
  yes = 0;
  boarder = find_object(XANDRIA_VIRTUAL "tunnels/" + (x + 1) + "," + (y));
  if (boarder) 
    if (boarder->GetExit("west")) yes = 1;
  boarder = 0;
  if (!random(4)  || yes) {
      e = TUNNELS_ROOM + (x+1) + "," + (y);
   }
  yes = 0;
  boarder = find_object(XANDRIA_VIRTUAL "tunnels/" + (x - 1) + "," + (y));
  if (boarder) 
    if (boarder->GetExit("east")) yes = 1;
  boarder = 0;   
  if (!random(4)  || yes) {
      w = TUNNELS_ROOM + (x-1) + "," + (y);
   }
  if (!random(4) || load_object(XANDRIA_VIRTUAL "desert/" + x + "," + y)->GetEnter("tunnel")) {
    u = XANDRIA_VIRTUAL "desert/" + (x) + "," + (y);
  }
  if (x <  20 && x > 0) w = 0;
  if (x > -20 && x < 0) e = 0;
  if (y >= 0) n = 0;
  if (y <= -10) s = 0;
  if (ne) AddExit("northeast", ne);
  if (se) AddExit("southeast", se);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (u) AddExit("up", u);
  if (!sizeof(GetExits())) AddExit("up", XANDRIA_VIRTUAL "desert/" + (x) + "," + (y));
  
  Setup(x, y);
  counter = 0;
 }

void Setup(int x, int y) {
  string *filteredexits;
  string long = "";
  filteredexits = GetExits();
  filteredexits -= ({ "up" });
  long += "The walls of the tunnel seem to be smoothly shaped and well maintained. Dim light glows from some smaller rocks that are embedded " +
          "deeply into the ceiling of the tunnel.";
  if (sizeof(filteredexits)) long += " The tunnels lead off to the " + conjunction(filteredexits) + " from here.";
    else long += "The tunnel seems to be little more than a deep hole with little directional depth.";
  if (GetExit("up")) long += " A tunnel leads up to the surface from here.";
  SetLong(long);
  SetSmell("The air has a slightly oily smell to it.");
  if (!random(7)) {
    AddInventory(TUNNELS_NPC "liz_worker", random(3)+1);
  }
  if (!random(9)) {
    AddInventory(TUNNELS_NPC "liz_warrior", random(3)+1);
  }
}

void heart_beat() {
	::heart_beat();
  foreach (object o in deep_inventory(this_object())) {
    if (userp(o)) return;
  }
  counter++;
  if (counter > 5)
    eventDestruct();
}
