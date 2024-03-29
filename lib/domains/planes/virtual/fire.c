/*  The plane of Fire.
 *  Not a pleasant place to be.
 */
#include <lib.h>
#include <domains.h>
#include "../planes.h"
#define WHAT_PLANE "fire"
inherit LIB_ROOM;
#include "fire/fire.h"
void Setup();
private int XPosition, YPosition, counter;

varargs static void create(int x, int y) {
  room::create();
  XPosition = x;
  YPosition = y;
  SetShort("on the plane of Fire");
  SetProperty("no weather", 1);
  SetProperty("no teleport", 1);
  SetProperty("lower plane",1);
  SetClimate("arid");
  AddExit("north", FIRE_PLANE + x + "," + (y + 1) );
  AddExit("south", FIRE_PLANE + x + "," + (y - 1) );
  AddExit("west", FIRE_PLANE + (x - 1) + "," + (y) );
  AddExit("east", FIRE_PLANE + (x + 1) + "," + (y) );
  Setup();
  set_heart_beat(1);
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
  long += "There is a radiant pillar of light to the " + tmp + ".";
  SetSmell( ([
     "default" : Smells[random(sizeof(Smells))],
    ]) );
  SetItems( ([
     "pillar" : "The pillar of light seems to lie directly in the center of the plane.",
     "light" : "The pillar of light seems to lie directly in the center of the plane.",
     ]) );
  if (XPosition == 0 && YPosition == 0) {
    long += "There is an enormous pillar of light reaching to the sky here.";
    AddEnter("pillar", YOZRATH_TOWNS "yozrath/room/oasis2");

    }
  SetLong(long);
  if(!random(15)) AddInventory(PLANE_NPC + "fire_elemental", random(2));
  if(!random(5)) AddInventory(PLANE_NPC + "lesser_fire", random(3));
  if(!random(20)) AddInventory(PLANE_NPC + "gfire_elemental", random(2));
  if(!random(20)) AddInventory(PLANE_NPC + "planeswalker", 1);
  if (!random(25)) AddInventory(PLANE_NPC "pf", random(2));
  if (XPosition > 500 || YPosition > 500 || XPosition < -500 || YPosition < -500) {
    if (!random(500)) AddInventory(PLANE_NPC "hephaeston", 1);
    }
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
