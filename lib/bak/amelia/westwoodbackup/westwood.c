#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;
#include "westwood.h"

#define WESTWOOD "/domains/westwood/virtual/westwood/"
#define HIKER_AREA WESTWOOD_DIR + "/areas/hiker/room/trailhead"
#define GOBLINCAMP WESTWOOD_DIR + "/areas/goblin_camp/room/camp_road_01"
#define DUNEDAIN_FOREST WESTWOOD_DIR + "/areas/dunedain_forest/room/forest1"
#define MONASTERY WESTWOOD_DIR + "/areas/monastery/room/ent"
#define ROOKLAIR WESTWOOD_DIR + "/areas/rooklair/obj/rope1"
#define SOLEILROAD VIRTUAL + "soleilroad/0,20"

static void create(int x, int y) {
  string n, e, s, w, ne, nw, se, sw;
  string long = "", short = "", smell = "", listen = "", tlong = "";
  string array RandomNPCs;
  string array OkEx, NoOk;

  mapping items = ([ ]);
  mapping itemadj = ([ ]);

  room::create();

/*  Setting Exits */

  n = WESTWOOD + (x) + "," + (y + 1);
  s = WESTWOOD + (x) + "," + (y - 1); 
  e = WESTWOOD + (x + 1) + "," + (y);
  w = WESTWOOD + (x - 1) + "," + (y);
  ne = WESTWOOD  + (x + 1) + "," + (y + 1);
  se = WESTWOOD  + (x + 1) + "," + (y - 1);
  nw = WESTWOOD  + (x - 1) + "," + (y + 1);
  sw = WESTWOOD  + (x - 1) + "," + (y - 1);

/* Define basic boundaries.  Westwood goes from 0,0 to 29,29. */

  if (x > 28) { e = ne = se = 0; }
  if (x < 1)  { w = sw = nw = 0; }
  if (y > 28) { n = ne = nw = 0; }
  if (y < 1 ) { s = se = sw = 0; }

/* Define basic room settings */

  SetDomain("WestWood");
  SetClimate("temperate");
  SetGoMessage("The forest is too dense to proceed in that direction.");
  items = ([
                ({ "forest","westwood","woods","trees","tree" }) : (: GetLong :),
          ]);
  itemadj = ([ "forest" : ({ "tall","deciduous","stunted","pine","west" }) ]);


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
      break;
        case 11..13:
        SetInventory( ([ RandomNPCs[random(sizeof(RandomNPCs))] : 2 ]) );
      case 14..20:
       SetInventory( ([ RandomNPCs[random(sizeof(RandomNPCs))] : 2 ]) );
      break;
  }


/* Gives specifics to rooms--spiffy npc's, connections, etc.
 
/* The road to Soleil */
  if(x == 13) {
        tlong = "  The Soleil Road meanders through the forest, avoiding trees.  It "
                "manages to progress in a general north-south fashion, however.";

        items+= ([ "road" : "The road goes north and south.  It travels from "
                        "the rest of the world to Soleil." ]);
        short = "on the road to Soleil";
        if ( y==13 ) {
		// this room is replaced with a real file
                short = "entrance to Soleil";
                n = 0;
                nw = 0;
                ne = 0;
        }
        else if (y==17) {
                tlong +="  A large fence blocks progress to the south.  "
                        "The Soleil Road splits off and follows the "
                        "fence to the east and west.";
                s = 0;
                sw = 0;
                se = 0;
        }
        else if (y==29) {
		tlong = "  The Soleil Road changes directions here, meandering to "
			"the south and northeast.";
                ne = MONASTERY;
        }
	  else if (y==0) {
		tlong = "  The Soleil Road meanders through the forest, avoid trees. "
			"It manages to progress, in general, to the north and southeast.";
		se = SOLEILROAD;
	  }
  }
if(y==13) {
	switch(x) {
		case 0..9:
		case 18..29:
		break;
		case 10:
		tlong = "  The Soleil Road curves from the east to the north.";
		ne = 0;
		break;
		case 11:
		case 12:
		case 14:
		case 15:
		case 16:
		tlong = "  The Soleil Road meanders in an east-west direction, "
			"along the edge of a fence that blocks travel to the north.";
		n = ne = nw = 0;
		break;
		case 17:
		tlong = "  The Soleil Road curves from the west to the north.";
		nw = 0;
		break;
	}
  }
if(y==17) {
	switch(x) {
		case 0..9:
		case 18..29:
		break;
		case 10:
		se = 0;
		tlong = "  The Soleil Road curves from the south to the east.";
		break;
		case 13:
		break;
		case 11:
		case 12:
		case 14:
		case 15:
		case 16:
		tlong = "  The Soleil Road meanders in an east-west direction, "
			"along the edge of a fence that blocks travel to the south.";
		s = se = sw = 0;
		break;
		case 17:
		tlong = "  The Soleil Road curves from the west to the south.";
		sw = 0;
		break;
	}
  }
  if(x==17) {
		switch(y) {
		case 0..12:
		case 18..29:
		break;
		case 14..16:
		tlong = "  The Soleil Road meanders to the north and south, "
			"blocked to the west by a fence.";
		w = nw = sw = 0;
		break;
		}
  }
  if(x==10) {
		switch(y) {
		case 0..12:
		case 18..29:
		break;
		break;
		case 14..16:
		tlong = "  The Soleil Road meanders to the north and south, "
			"blocked to the east by a fence.";
		e = ne = se = 0;
		break;
		}
  }		
/*And here I add in all the areas*/
  if(x==0 && y==29) {
	tlong+= "  A path meanders off to the northwest.";
	short = "near a hiking path";
        items += ([ "path" : "The path heads out to the northwest." ]);
	nw = HIKER_AREA;
  }
  if(x==0 && y==20) {
	tlong+="  A valley opens up to the west.";
	short = "near a valley";
	items += ([ "valley" : "The valley is to the west." ]);
	w = DUNEDAIN_FOREST;
  }
  if(x==0 && y==10) {
	tlong +="  A trail heads off to the west.";
	short = "near a trail";
	items += ([ "trail" : "The trail goes westward." ]);
	w = GOBLINCAMP;
  }
  if(x==26 && y==25) {
	tlong += "  A dark, disgusting sinkhole goes down into the ground.";
	short = "near a sinkhole";
	items += ([ ({ "hole","sinkhole" }) : "The sinkhole is large "
		"enough to fit even a dragon.  A rope dangles down "
		"into it." ]);
	itemadj += ([ "hole" : ({ "dark","disgusting" }) ]);
	SetInventory( ([ ROOKLAIR : 1 ]) );
  }

  
/* Setting up the basic room */
   if(!long || long == "") {
      long = "Tall deciduous trees and stunted pine trees grow in the WestWood.  "
		"Small bushes and assorted green plants decorate the space "
		"in between.  A few small mushrooms gather in between the tree "
		"roots.  An odd stringy moss grows on some of the pine tree "
		"branches.";
	if(tlong && tlong != "") {
		long+= tlong;
	}
	OkEx = ({ });
	NoOk = ({ });
	if(n) { OkEx+= ({ "north" }); }
	else { NoOk += ({ "north" }); }
	if(ne) { OkEx+= ({ "northeast" }); }
	else { NoOk += ({ "northeast" }); }
	if(e) { OkEx+= ({ "east" }); }
	else { NoOk += ({ "east" }); }
	if(se) { OkEx+= ({ "southeast" }); }
	else { NoOk += ({ "southeast" }); }
	if(s) { OkEx+= ({ "south" }); }
	else { NoOk += ({ "south" }); }
	if(sw) { OkEx+= ({ "southwest" }); }
	else { NoOk += ({ "southwest" }); }
	if(w) { OkEx+= ({ "west" }); }
	else { NoOk += ({ "west" }); }
	if(nw) { OkEx+= ({ "northwest" }); }
	else { NoOk += ({ "northwest" }); }
	if(sizeof(NoOk)==0) { long += "  The WestWood sprawls out in all directions."; }
        else if(sizeof(NoOk)==1) { long += "  The WestWood sprawls out in all directions "
					"except to the " + NoOk[0] + ", where the "
					"dense bushes make travelling impossible."; }
	else if(sizeof(OkEx)==1) { long+= "  Thick bushes make travel impossible in "
					"all directions except " + OkEx[0] + "."; }
	else {
		long+="  The brush is broken enough to travel to the ";
		while(sizeof(OkEx) > 1) {
			long += OkEx[0] + ", ";
			OkEx-=({ OkEx[0] });
		}
// This next line sets up a more reasonable "you can't go this way" for around Soleil
		if(((y==13) && ((x>9) && (x<18))) || ((y==17) && ((x>9) && (x<18))) ||
			((x==10) && ((y==14) ||(y==15)|| (y==16))) || ((x==17) &&
			( (y==14) ||(y==15)|| (y==16))) ) {
                        long += "and " + OkEx[0] + ", but a long fence impedes travel "
				"to the ";
		}
		else {	long += "and " + OkEx[0] + ", but dense bushes impede travel "
				"to the ";
		}
		while(sizeof(NoOk) > 1) {
			long += NoOk[0] + ", ";
			NoOk-=({ NoOk[0] });
		}
		long += "and " + NoOk[0] + ".";
	}
   }                

/* Just in case they don't get anything special */
  if(!short || short == "") short = "inside the WestWood";
  if(!listen || listen == "") listen = "Birds chirp in the distance.";
  if(!smell || smell == "") smell = "The air is clean and refreshing.";

/* Actually set everything. */
  SetLong(long);
  SetShort(short);
  SetListen("default", listen);
  SetSmell("default", smell);
  SetItems(items);
  SetItemAdjectives(itemadj);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (se) AddExit("southeast", se);
  if (ne) AddExit("northeast", ne);
}

