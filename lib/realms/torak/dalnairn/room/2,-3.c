//
// Dalnairn Total Recode
// Torak@Haven
// 2014-2017
//

#include <lib.h>
#include <domains.h>
#include <dirs.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-tropical");
  SetShort("before a temple in a tropical forest");
  SetDayLong(
    "Densley clustered plant life grows between the tall "
    "trees in this wet with green forest. "
    "The canopy above glows with sunlight, saturating "
    "everything below it in a soft green hue. "
    "A polished stone temple has been erected here inside forest. "
    "A trampled path cuts through the forest. "
    "There is a large mountain ridge to the southeast. ",
  );
  SetNightLong(
    "Densley clustered plant life grows between the tall "
    "trees in this wet with green forest. "
    "The canopy above glows with moonlight, stars "
    "twinkling between the few gaps in the leaves. "
    "A polished stone temple has been erected here inside forest. "
    "A trampled path cuts through the forest. "
    "There is a large mountain ridge to the southeast. ",
  );
  SetItems( ([
    ({ "temple" }) :
       "The temple's grey stone walls have been polished to shine. "
       "The temple walls reach up into the canopy.",
    ({ "wall", "walls" }) :
       "The grey stone walls of the temple are polished to a shine. "
       "The walls soar into the air reaching for the canopy. ",
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
    "temple" : ({ "stone", "polished", "shining" }),
    "wall" : ({ "stone", "polished", "shining" }),
    "life" : ({ "plant", "tall", "green" }),
    "canopy" : ({ "above", "below" }),
    "path" : ({ "trampled" }),
    "ridge" : ({ "mountain" }),
  ]) );  
  SetInventory( ([
    DAL_OBJ "flag_pole" : 1,
    DAL_OBJ "black_truffle" : 1 + random(3),
    DAL_OBJ "r_plant" : 1 + random(3),
  ]) );
  SetListen( ([
    "default" : "Branches creak as parakeets chatter in the distance.",
  ]) );
  SetSmell( ([
    "default" : "The air is thick and damp.",
  ]) );
  SetExits( ([
    "north" : DAL_ROOM "2,-2.c",
    "west" : DAL_ROOM "1,-3.c",
    "northeast" : DAL_ROOM "3,-2.c",
    "southwest" : DAL_ROOM "1,-4.c",
  ]) ); 
  SetEnters( ([
    "temple" : DAL_BLD "temple_01",
  ]) );
}
