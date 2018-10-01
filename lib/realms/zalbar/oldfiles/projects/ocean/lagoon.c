/*  The Ice Lagoon 
    Thoin@Haven
    4/16/07
*/

#include <lib.h>
#include <domains.h>
//#include "../areas/lagoon/lagoon.h"
#include "../lagoon.h"
inherit LIB_ROOM;

static void create(int x, int y) {
  string n, e, s, w, ne, nw, se, sw;
  string long = "";
  string array OkEx, NoOk;
  mapping inv = ([ ]), items = ([ ]);

  room::create();

/*  Setting Exits */
  set_heart_beat(1);


  if (x > -30) w = GUROV_VIRTUAL "lagoon/" + (x - 1) + "," + y;
  if (x <  30) e = GUROV_VIRTUAL "lagoon/" + (x + 1) + "," + y;
  if (y > -30) s = GUROV_VIRTUAL "lagoon/" + (x) + "," + (y - 1);
  if (y <  30) n = GUROV_VIRTUAL "lagoon/" + (x) + "," + (y + 1);


/*  SetShort and SetObviousExits */

  SetShort("in a cold lagoon");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetDomain("Gurov");
  SetWarmth(-10);
  SetGoMessage("The icy water is too deep to continue in that direction.");

/*  Make a default Long */

  long = "The lagoon is about a foot deep except in a few places where the ice "
         "comes through the surface. The water is frigid and absolutely "
         "still except for slight ripples from water drops. ";

/*  Make default items based on the above long */

  items = ([
       ({ "ice", "islands", "small islands" }) : 
           "Under the water which makes up the lagoon is ice, the "
           "ice comes through the surface of the water in places making small islands.",
       ({ "water", "drop", "ripples", "small ripples" }) : 
           "The water is still except for the drops that cause small ripples across the surface.",
  ]);

  if (x == 0 && y == -30)  { s = WORLD_SOUTH; }
  /* if (x == 30 && y == -15) { e = WORLD_EAST; }   Removed */
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);

  NoOk = ({ "north", "south", "east", "west" });
  NoOk -= GetExits();
  if (sizeof(NoOk) == 0) { long += " The lagoon continues in all directions.";   }
  if (sizeof(NoOk) == 1) { long += " The lagoon spreads out in all directions except the " + NoOk[0] + ", where it appears to get very deep.";   }
  if (sizeof(GetExits()) > 1 && sizeof(NoOk) > 1) {
    long += " The lagoon continues to the " + conjunction(GetExits(), "and") + " but appears too deep to the " + conjunction(NoOk, "and") + ".";
  }
/*  Make a default inventory, if it needs one */

  if (!random(5)) {
    inv[LAGOON_NPC "greater_water_elemental"] = (random(2) + 2);
  }
  if (!random(2)) {
    inv[LAGOON_NPC "water_elemental"] = (random(2) + 1);
  }

  SetInventory(inv);
  SetLong(long);
  SetItems(items);
  SetListen( ([ "default" : "The sound of rushing water echoes across the lagoon." ]) );
  SetSmell(  ([ "default" : "The smell of fresh water fills the area." ]) );
}


void heart_beat() {
        ::heart_beat();
  if (!sizeof(filter(deep_inventory(this_object()), (: living :) ))) {
//      debug("Cleaned " + base_name(this_object()));
    eventDestruct();
  }
}
