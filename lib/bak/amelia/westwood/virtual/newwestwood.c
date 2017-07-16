#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
#include "westwood.h"
#define WESTWOOD "/realms/amelia/virtual/newwestwood"



static void create(int x, int y) {
  string n, e, s, w, ne, nw, se, sw;
  string long = "", short = "", smell = "", listen = "";
  string array RandomNPCs;

  mapping items = ([ ]);

  SetNoReplace(1);
  room::create();

/*  Setting Exits */

  n = WESTWOOD + (x) + "," + (y + 1);
  s = WESTWOOD + (x) + "," + (y - 1); 
  e = WESTWOOD + (x + 1) + "," + (y);
  w = WESTWOOD + (x - 1) + "," + (y);
  ne = WESTWOOD + (x + 1) + "," + (y + 1);
  se = WESTWOOD + (x + 1) + "," + (y - 1);
  nw = WESTWOOD + (x - 1) + "," + (y + 1);
  sw = WESTWOOD + (x - 1) + "," + (y - 1);

/* Define basic boundaries.  Westwood goes from 0,0 to 29,29. */

  if (x > 28) { e = 0; }
  if (x < 1)  { w = 0; }
  if (y > 28) { n = 0; }
  if (y < 1 ) { s = 0; }

/* Define basic room settings */

  SetDomain("WestWood");
  SetClimate("temperate");
  SetGoMessage("The forest is too dense to proceed in that direction.");

/* Gives flavor to rooms.  Random NPC's. */

  RandomNPCs = ({
		W_NPC + "muezzin",
		W_NPC + "halfling",
		W_NPC + "gelfling",
		W_NPC + "bear",
		W_NPC + "knight",
		W_NPC + "blue_jay",
		W_NPC + "butterfly",
		W_NPC + "deer",
		W_NPC + "deermouse",
		W_NPC + "rabbit",
		W_NPC + "raven",
		W_NPC + "robin",
		W_NPC + "tarantula",
		W_NPC + "wolf",
		W_NPC + "protect",
		});

  switch(random(50)) {
	case 0..10:
	SetInventory( ([ RandomNPCs[random(sizeof(RandomNPCs))] : 1 ]) );
	return;
  }


/* Gives specifics to rooms--spiffy npc's, connections, etc.
 

  if(!long) long = "Look, a WestWood!  Cooooool.";
  if(!short) short = "shortie";
  if(!listen) listen = "listen";
  if(!smell) smell = "smell";

/* Actually set everything. */
  SetLong(long);
  SetShort(short);
  SetListen("default", listen);
  SetSmell("default", smell);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (se) AddExit("southeast", se);
  if (ne) AddExit("northeast", ne);
}
