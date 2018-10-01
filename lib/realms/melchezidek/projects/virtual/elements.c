/*
 *
 *  Pentagram walkway for
 *  elemental towers
 *  -Melchezidek July 2009
 */

#include <lib.h>
#include <domains.h>
#include "/realms/melchezidek/projects/elements/elements.h"
inherit LIB_ROOM;

static void create(int x, int y) {
  string n, e, s, w, ne, se, nw, sw;
  string long = "";
  string array OkEx, NoOk;
  mapping inv = ([ ]), items = ([ ]);


  room::create();

/*  Setting Exits */

  set_heart_beat(17);

/* First Branch, NE-SW */
  if((x == y) && (x <= 12) && (x >= 2)) {
  	 ne = EL_VIR + (x + 1) + "," + (y + 1);
  	 sw = EL_VIR + (x - 1) + "," + (y - 1);
  	}
/* Second Brach, W-E */
  if(y == 13) {
  	if((x != 1) && (x != 13)) {
  		e = EL_VIR + (x + 1) + "," + y;
  		w = EL_VIR + (x - 1) + "," + y;
  	}
  	if(x == 1) {
  		e  = EL_VIR + (x + 1) + "," + y;
  		se = EL_VIR + (x + 1) + "," + (y - 2);
  	}
  	if(x == 13) {
  		w  = EL_VIR + (x - 1) + "," + y;
  		sw = EL_VIR + (x - 1) + "," + (y - 1);
  	}
  }
/* Third Branch, SE-NW */
  if((x > 0) && (x < 14) && (((y - 13) / x ) == -1)) {
  	nw = EL_DIR + (x - 1) + "," + (y + 1);
  	se = EL_DIR + (x + 1) + "," + (y - 1);
  }
  
  
/*  SetShort and SetObviousExits */

  SetShort("upon the Path of Elements");
  SetClimate("temperate");
  SetAmbientLight(20);
  SetWarmth(0);
  SetGoMessage("The path does not go that way.");

  
/*  Make a default Long */

  long = "The path itself seems to glow slightly from beneath the dirt."
         " Years of use by magi have left it well developed and yadda.";

/*  Make default items based on the above long */

          
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (ne) AddExit("northeast", ne);
  if (nw) AddExit("northwest", nw);
  if (se) AddExit("southeast", se);
  if (sw) AddExit("southwest", sw);

  NoOk = ({ "north", "south", "east", "west", "northeast", "southwest", "northwest", "southeast" });
  NoOk -= GetExits();
  if (sizeof(NoOk) == 0) { long += " The catacombs continue in all directions.";   }
// if (sizeof(NoOk) == 1) { long += " The walls of the catacombs prevent movement to the " + NoOk[0] + ".";   }
  if (sizeof(GetExits()) > 1 && sizeof(NoOk) > 1) {
    long += " The path of elements continues to the " + conjunction(GetExits(), "and") + ".";
  }
  
/*  Make a default inventory, if it needs one */


//  SetInventory(inv);
  SetLong(long);
  SetItemAdjectives( ([
     ]) );
  
  switch(random(2)) {
  case 0:
     SetListen( ([ "default" : "The soft hum of magical energies are all about." ]) );
     break;
    case 1:
     SetListen( ([ "default" : "Animalistic shrieks interrupt the silence."
                ]) );
     break;
    }
                          
  SetSmell( ([ "default"  : "The lack of an odour is offputting." ]) );
}


void heart_beat() {
        ::heart_beat();
  if (!sizeof(filter(deep_inventory(this_object()), (: living :) ))) {
    eventDestruct();
  }
}
