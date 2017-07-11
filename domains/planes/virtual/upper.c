/*  The first lower plane.
 *  Not sure exactly what I will call it just yet.
 */
#include <lib.h>
#include <domains.h>
#include "../planes.h"
inherit LIB_ROOM;
void Setup(int, int);
int PreventWander();
int counter;

varargs static void create(int x, int y) {
  room::create();
  SetShort("in the First Upper Plane");
  SetProperty("no weather", 1);
  SetProperty("lower plane",1);
  SetProperty("no teleport", 1);
  SetClimate("temperate");
  AddExit("north", DOMAIN_PLANES "virtual/upper/" + x + "," + (y + 1) );
  AddExit("south", DOMAIN_PLANES "virtual/upper/" + x + "," + (y - 1) );
  AddExit("west" , DOMAIN_PLANES "virtual/upper/" + (x - 1) + "," + (y) );
  AddExit("east" , DOMAIN_PLANES "virtual/upper/" + (x + 1) + "," + (y) );
  Setup(x, y);
  counter = 0;
}

void Setup(int x, int y) {
   string long = "";
   string tmp;
  
  long = "From here, the misty white cloud that makes up the First Upper Plane expands out "
         "endlessly in all directions. A cool breeze blows through the plane, lightly stirring "
         "the cloud and giving a refreshing feeling to the area.";
  if (y) {
    if (y > 0) tmp = "south";  else tmp = "north";
  } else tmp = "";
  if (x) {
    if (x > 0) tmp += "west"; else tmp += "east";
  }
  if (tmp != "") 
    long += " A large statue of the Lord of Order lies to the " + tmp + ".";
  SetListen( ([
    "default" : "A soft choir of Angels sings in the distance.",
    ]) );
  SetItems( ([
     "statue" : "The statue looms as the primary feature of the land.",
     ]) );
  if (x == 0 && y == 0) {
    long += " There is a large statue here towering over the clouds.";
    SetItems( ([
      "statue" : "The statue of the Lord of Order rises into the majestic heights of this plane. The base of the "
                 "statue contains a small glowing portal.",
      "portal" : "The portal appears to lead back to the mortal world of Kailie.",
      ]) );
     AddEnter("portal", WESTWOOD_VIRTUAL "westwood/0,30", (: PreventWander :) );
  }
  SetLong(long);
  if (!random(10)) {
    AddLong(" There appears to be a furry thing inhabitation here.");
    AddInventory(PLANE_NPC "thing", 3);
    AddInventory(PLANE_NPC "large_thing", 2);
  }
  if (!random(10))
    AddInventory(PLANE_NPC "planeswalker",1);
  if (!random(10))
    AddInventory(PLANE_NPC "archangel", 1);
  if (!random(15))
    AddInventory(PLANE_NPC "scion", 1);
  if (!random(15))
    AddInventory(PLANE_NPC "seraph", 1);
  if (!random(5))
    AddInventory(PLANE_NPC "pegasus", 2);
 if (!random(10))
    AddInventory(PLANE_NPC "air_elemental", 1);
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


int PreventWander() {
  if (!userp(this_player())) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
