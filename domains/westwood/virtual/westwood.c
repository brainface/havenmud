#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
#include "westwood.h"

static void create(int x, int y) {
  string n, e, s, w, ne, nw, se, sw;
  string long = "", short = "", smell = "", listen = "", tlong = "";
  string array RandomNPCs;
  string array OkEx, NoOk;

  mapping items = ([ ]);
  mapping itemadj = ([ ]);

  room::create();

/*  Setting Exits */

  n  = WESTWOOD_VIRTUAL  "westwood/" + (x)     + "," + (y + 1);
  s  = WESTWOOD_VIRTUAL  "westwood/" + (x)     + "," + (y - 1); 
  e  = WESTWOOD_VIRTUAL  "westwood/" + (x + 1) + "," + (y);
  w  = WESTWOOD_VIRTUAL  "westwood/" + (x - 1) + "," + (y);
  ne = WESTWOOD_VIRTUAL  "westwood/" + (x + 1) + "," + (y + 1);
  se = WESTWOOD_VIRTUAL  "westwood/" + (x + 1) + "," + (y - 1);
  nw = WESTWOOD_VIRTUAL  "westwood/" + (x - 1) + "," + (y + 1);
  sw = WESTWOOD_VIRTUAL  "westwood/" + (x - 1) + "," + (y - 1);

/* Define basic boundaries.  Westwood goes from 0,0 to 29,29. */

  if (x >= 30) { e = ne = se = 0; }
  if (x == 0)  { w = sw = nw = 0; }
  if (y >= 30) { n = ne = nw = 0; }
  if (y == 0 ) { s = se = sw = 0; }
  if (x < 0 || y < 0) { n = s = e = w = ne = nw = se = sw = 0; } /* This room shouldn't exist! */

/* Define basic room settings */
  
  SetClimate("temperate");
  SetGoMessage("The forest is too dense to proceed in that direction.");
  
/* Gives flavor to rooms.  Random NPC's. */

  RandomNPCs = ({
    W_NPC + "muezzin",
    W_NPC + "halfling",
    W_NPC + "gelfling",
    W_NPC + "bear",
    W_NPC + "blue_jay",
    W_NPC + "butterfly",
    W_NPC + "deer",
    W_NPC + "deermouse",
    W_NPC + "rabbit",
    W_NPC + "raven",
    W_NPC + "robin",
    W_NPC + "tarantula",
    W_NPC + "wolf",
  });

  switch(random(50)) {
      case 0..10:
        SetInventory( ([ RandomNPCs[random(sizeof(RandomNPCs))] : 1 ]) );
      break;
      case 11..13:
        SetInventory( ([ RandomNPCs[random(sizeof(RandomNPCs))] : 2 ]) );
      case 14..20:
        SetInventory( ([ RandomNPCs[random(sizeof(RandomNPCs))] : 2 ]) );
      break;
  }
 
/* Setting up the basic room */
    
  long = 
    "Tall deciduous trees and stunted pine trees grow in the WestWood. "
		"Small bushes and assorted green plants decorate the space "
		"in between. A few small mushrooms gather in between the tree "
		"roots. An odd stringy moss grows on some of the pine tree "
		"branches.";

/* Special Room! */

  if (x == 15 && y == 4) {
    AddInventory(W_NPC + "phayla", 1);
}
  if (x == 0 && y == 20) {
    AddExit("west", WESTWOOD_AREAS + "dunedain_forest/room/forest1");
    long += " A path leads through the brush to the west.";
    items += ([ ({ "path", }) : "The path leads through the thick brush to the west." ]);
    } 
  if (x == 0 && y == 10) {
    AddExit("west", WESTWOOD_AREAS + "goblin_camp/room/camp_road_01");
    long += " A camp can be seen to the west through the thick brush. ";
    items += ([ ({ "camp", }) : "The small camp looks like it is a invading force of goblins "
                                "waiting for the right time to strike." ]);
    } 
  if (x == 26 && y == 25) {
    AddInventory(WESTWOOD_AREAS "rooklair/obj/rope1", 1);
    long += " A large sinkhole falls away into the depths of the forest floor. "
            "A rope has been attached to the side of the pit, making it possible "
            "to climb down into the darkness.";
    items += ([ ({ "pit", "sinkhole", "hole", }) : "This sinkhole is large. It could "
                                                   "be the lair of a very large animal." ]);
    }	
  if (x == 0 && y == 30) {
    AddInventory(WESTWOOD_VIRTUAL "obj/duuk_statue", 1);
    long += " A swirling portal is built into the base of the statue.";
    items += ([ "portal" : "The portal has a wispy white cloudiness to it." ]);
    
  }
/*  if (x == 10 && y == 10) {
    AddInventory(WESTWOOD_TOWNS "thra/obj/tree", 1);
    long += " A massive yet climbable tree sits at the side of this section of the Westwood.";
  } */
/* Exits */
	
	if (x == 30 && y == 0) {  se = WESTWOOD_TOWNS "soleil/room/soleilroad02";  }  /* Connector Room */
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (se) AddExit("southeast", se);
  if (ne) AddExit("northeast", ne);

	NoOk = ({ "north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest" });
	NoOk -= GetExits();
	
	if (sizeof(NoOk) == 0) { 
	  long += " The WestWood sprawls out in all directions."; 
	  }
  if (sizeof(NoOk) == 1) { 
    long += " The WestWood sprawls out in all directions except the " + NoOk[0] + 
            ", where the dense bushes make travelling impossible."; 
    }
	if (sizeof(GetExits()) == 1) { 
	  long+= " Thick bushes make travel impossible in all directions except " + OkEx[0] + "."; 
	  }
	if (sizeof(GetExits()) > 1 && sizeof(NoOk) > 1) {
		long+=" The brush is broken enough to travel to the " + conjunction(GetExits(), "and") + ".";
		}

/* Just in case they don't get anything special */
  if(!short || short == "")   short = "inside the WestWood";
  if(!listen || listen == "") listen = "Birds chirp in the distance.";
  if(!smell || smell == "")   smell = "The air is clean and refreshing.";

/* Actually set everything. */
  SetLong(long);
  SetShort(short);
  SetListen("default", listen);
  SetSmell("default", smell);
  SetItems(items);
  SetItemAdjectives(itemadj);
  if (x == 0 && y == 30) AddEnter("portal", DOMAIN_PLANES "virtual/upper/0,0");
}

