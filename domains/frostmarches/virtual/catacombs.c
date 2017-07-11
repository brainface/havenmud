/*
 *
 * Durgoroth Catacombs
 * Melchezidek@Haven 2007
 *
 */

#include <lib.h>
#include <domains.h>
#include "/domains/frostmarches/areas/catacombs/cata.h"
inherit LIB_ROOM;

int PreExit();
static void create(int x, int y) {
  string n, e, s, w, u;
  string long = "";
  string array OkEx, NoOk;
  mapping inv = ([ ]), items = ([ ]);
  float dden = 5.0;
  int den = 5;
  int xnum = x;
  int ynum = y;

  room::create();

/*  Setting Exits */

  set_heart_beat(1);

  if((ynum/dden) == (ynum/den)) {
         if (x > 0) w = FROSTMARCHES_VIRTUAL "catacombs/" + (x - 1) + "," + y;
         if (x <  60) e = FROSTMARCHES_VIRTUAL "catacombs/" + (x + 1) + "," + y;
        }
  if((xnum/dden) == (xnum/den)) {
         if (y > 0) s = FROSTMARCHES_VIRTUAL "catacombs/" + (x) + "," + (y - 1);
         if (y <  60) n = FROSTMARCHES_VIRTUAL "catacombs/" + (x) + "," + (y + 1);
        }
  if(x == 0 && y == 0) {
               e = FROSTMARCHES_VIRTUAL "catacombs/" + (x + 1) + "," + y;
               n = FROSTMARCHES_VIRTUAL "catacombs/" + (x) + "," + (y + 1);
               AddExit("up", CATA_ROOM "stair8", (: PreExit :));
        }


/*  SetShort and SetObviousExits */

  SetShort("within the Ancient Durgoroth Catacombs");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetDomain("Frostmarches");
  SetWarmth(0);
  SetGoMessage("The walls of the catacombs prevent movement in that direction.");

  
/*  Make a default Long */

  long = "Years of dust and debris have caked the walls of these ancient"
         " catacombs. The walls"
         " have multiple recesses in them, some of which hold caskets"
         " others, which are seemingly empty. Randomly placed along"
         " the wall are sconces for torches, which have long since"
         " burnt out. The floor is covered in a thin layer of water"
         " and mold creeps up the walls just above it's surface.";

/*  Make default items based on the above long */

  items = ([
         ({ "walls", "wall" }) :
          "The walls are caked in layers of dust. Rectangle"
          " recesses have been dug into the walls to provide"
          " a resting place for the dead. Near the water"
          "-covered floor, mold slowly creeps its way up"
          " the walls.",
         ({ "recess", "recesses", "caskets", "resting place", "place" }) :
          "Most of the recesses are home to caskets of various"
          " makes and sizes.",
         ({ "sconces", "sconce", "torch", "torches" }) :
          "Randomly placed along the wall are sconces that hold"
          " old, burnt out torches that were used to light"
          " the way down the corridor years ago.",
         ({ "water", "floor", "mold", "feces", "bacteria", "surface" }) :
          "Roughly two inches of water cover the floor."
          " It is dark and fetid looking and is probably"
          " the home of countless bacteria and pieces of"
          " feces. Along the base of the walls near the"
          " water, mold has begun to grow.",
         ({ "catacomb", "catacombs", "corridor", "corridors" }) :
          (: GetLong :),
         ({ "casket", "caskets" }) :
         "The few caskets that are left are old and battered. They"
         " look as if they have been here quite some time.",
          ]);
          
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (u) AddExit("up", u);

  NoOk = ({ "north", "south", "east", "west" });
  NoOk -= GetExits();
  if (sizeof(NoOk) == 0) { long += " The catacombs continue in all directions.";   }
  if (sizeof(NoOk) == 1) { long += " The walls of the catacombs prevent movement to the " + NoOk[0] + ".";   }
  if (sizeof(GetExits()) > 1 && sizeof(NoOk) > 1) {
    long += " The catacombs continue to the " + conjunction(GetExits(), "and") + ".";
  }
  
/*  Make a default inventory, if it needs one */
  switch(random(3)) {
   case 0:
      if (!random(5)) {
         inv[CATA_NPC "banshee"] = (random(2) + 2);
        }
      if (!random(2)) {
         inv[CATA_NPC "skeleton"] = (random(2) + 1);
        }
      if (!random(4)) {
         inv[CATA_NPC "zombie"] = (random(2) + 1);
        }
      break;
   case 1:
      if (!random(8)) {
         inv[CATA_NPC "golem"] = 1;
        }
      break;
   case 2:
      if (!random(4)) {
         inv[CATA_NPC "imp"] = (random(1) + 1);
        }
      break;
   }
 
  if (!random(20)) {
    inv[CATA_OBJ "casket"] = 1;
  }

  SetInventory(inv);
  SetLong(long);
  SetItems(items);
  SetItemAdjectives( ([
     "water" : ({"dark", "fetid", "layer of"}),
     "dust" : ({ "layer of" }),
     "feces" : ({ "pieces of" }),
     "bacteria" : ({ "countless" }),
     "walls" : ({ "base of" }),
     "recess" : ({ "multiple" }),
     "torch" : ({ "burnt", "burnt out", "old" }),
     "floor" : ({ "water-covered", "covered" }),
     "catacomb" : ({ "ancient" }),
     ]) );
  
  switch(random(2)) {
  case 0:
     SetListen( ([ "default" : "The sound of footsteps echo through the"
                          " ancient halls." ]) );
     break;
    case 1:
     SetListen( ([ "default" : "The sound of splashing water can be heard."
                ]) );
     break;
    }
                          
  SetSmell( ([ "default"  : "The air smells stale and fetid." ]) );
}


void heart_beat() {
        ::heart_beat();
  if (!sizeof(filter(deep_inventory(this_object()), (: living :) ))) {
    eventDestruct();
  }
}

int PreExit() {
  if (this_player()->id("cata_npc")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
