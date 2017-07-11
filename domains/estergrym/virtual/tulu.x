#include <lib.h>
#include "/domains/estergrym/areas/tulu/tulu.h"
inherit LIB_ROOM;
int counter;

void SetupExits(int, int);

static void create(int x, int y) {
  ::create();
  SetShort("inside the Tulu Catacombs");
  SetInventory( ([
    TULU_NPC "cultist_fighter" : random(4),
    TULU_NPC "cultist_priest"  : random(3),
    ]) );
  SetClimate("underground");
  SetupExits(x, y);
  SetLong(
    "The Catacombs continue to the " + conjunction(GetExits(), "and") + " from here. The black stonework "
    "gives a bone-chilling appearance, and carved into the stone walls are images of pure evil. Strange "
    "images of floating octopus-looking beings seem to be tormenting the various sentient races of Kailie, "
    "and death and chaos seem to reign supreme. Various stains of ancient battle line the floor."
    );
  SetSmell("A coppery smell of death, filth, and decay lines the air.");
  if (x == 15 && y == 0) AddInventory(TULU_NPC "tulu", 1);
  counter = 0;
}

void SetupExits(int x, int y) {
  string n, e, s, w;
  
  n = TULU_VIRTUAL + (x) + "," + (y + 1);
  s = TULU_VIRTUAL + (x) + "," + (y - 1);
  if (y == 15) n = 0;
  if (y == 0 ) s = 0;
  if (y == 15) {
    if (x % 2 == 0) e = TULU_VIRTUAL + (x + 1) + "," + (y);
    if (x % 2 == 1) w = TULU_VIRTUAL + (x - 1) + "," + (y);
  }
  if (y == 0) {
    if (x % 2 == 1) e = TULU_VIRTUAL + (x + 1) + "," + (y);
    if (x % 2 == 0) w = TULU_VIRTUAL + (x - 1) + "," + (y);
  }
  if (x == 15) e = 0;
  if (x == 0 ) w = 0;
  if (x == 0 && y == 0) s = TULU_ROOM + "under01";
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east" , e);
  if (w) AddExit("west" , w);
}


/*  This is to stop a massive issue. Massive. */

void heart_beat() {
	::heart_beat();
  foreach (object o in deep_inventory(this_object())) {
    if (userp(o)) return;
  }
  counter++;
  if (counter > 120)
    eventDestruct();
}
