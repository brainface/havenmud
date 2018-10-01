#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-tropical");
  SetShort("a tropical forest");
  SetDayLong(
    "Densley clustered plant life grows between the tall "
    "trees in this wet with green forest. "
    "The canopy above glows with sunlight, saturating "
    "everything below it in a soft green hue. "
    "A trampled path cuts through the forest. "
    "A waterfall flows from the top of the ridge arm "
    "collecting into a creek. A wooden building has "
    "been erected next to the creek.",
  );
  SetNightLong(
    "Densley clustered plant life grows between the tall "
    "trees in this wet with green forest. "
    "The canopy above glows with moonlight, stars "
    "twinkling between the few gaps in the leaves. "
    "A trampled path cuts through the forest. "
    "A waterfall flows from the top of the ridge arm "
    "collecting into a creek. A wooden building has "
    "been erected next to the creek.",
  );
  SetItems( ([
    ({ "pool", "water" }) :
       "A small pool of water collects at the base of the waterfall "
       "where the water smashes upon a rocks. "
       "A creek empties out of the pool flowing to the west. ", 
    ({ "smithy", "building" }) :
       "A wooden building has been erected here next to the creek.",
    ({ "rock", "rocks"}) :
       "Large and smooth these rocks shine in the light and water "
       "smashing upon them from the waterfall above.",
    ({ "waterfall", "floe" }) :
       "Falling from the ridge arm a waterfall flows down "
       "smashing upon the rocks below emptying into a pool and creek. ",
    ({ "life", "trees", "hue", "forest" }) : (: GetLong :),
    ({ "canopy", "branches", "leaves" }) : 
       "The tallest trees here reach out together and form the canopy "
       "with their tallest branches and leaves.",
    ({ "path" }) :
       "The path through the forest runs parallel to the mountain ridge.",
    ({ "ridge" }) :  
       "The forest grows to the edge of a mountain ridge. "
       "The top of the ridge can not be seen from here.",
  ]) );
  SetItemAdjectives( ([
    "pool" : ({ "small" }),
    "building" : ({ "wooden" }),
    "waterfall" : ({ "flowing" }),
    "creel" : ({ "flowing" }),
    "life" : ({ "plant", "tall", "green" }),
    "canopy" : ({ "above", "below" }),
    "path" : ({ "trampled" }),
    "ridge" : ({ "mountain" }),
  ]) );  
  SetInventory( ([
    DAL_OBJ "creek" : 1,
    DAL_NPC "monk_parakeet" : random(2),
    DAL_NPC + "monkey" : random(2),
    DAL_OBJ "r_plant" : 2 + random(3),
  ]) );
  SetListen( ([
    "default" : "Water smashes upon rocks.",
  ]) );
  SetSmell( ([
    "default" : "The air is thick and damp.",
  ]) );
  SetExits( ([
    "north" : DAL_ROOM "3,-1.c",
    "west" : DAL_ROOM "2,-2.c",
    "southwest" : DAL_ROOM "2,-3.c",
  ]) ); 
  SetEnters( ([
    "smithy" : DAL_BLD + "smithy_01",
  ]) );
}
