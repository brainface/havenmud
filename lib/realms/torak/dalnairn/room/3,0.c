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
  SetShort("a tropical forest");
  SetDayLong(
    "Densley clustered plant life grows between the tall "
    "trees in this wet with green forest. "
    "The canopy above glows with sunlight, saturating "
    "everything below it in a soft green hue. "
    "A trampled path cuts through the forest. "
    "There is a large mountain ridge to the east. ",
  );
  SetNightLong(
    "Densley clustered plant life grows between the tall "
    "trees in this wet with green forest. "
    "The canopy above glows with moonlight, stars "
    "twinkling between the few gaps in the leaves. "
    "A trampled path cuts through the forest. "
    "There is a large mountain ridge to the east. ",
  );
  SetItems( ([
    ({ "life", "trees", "hue", "forest" }) : (: GetLong :),
    ({ "canopy", "branches", "leaves" }) : 
       "The tallest trees here reach out together and form the canopy "
       "with their tallest branches and leaves.",
    ({ "path" }) :
       "The path through the forest runs parallel to the mountain ridge "
       "and also leads east from here towards the ridge.",	
    ({ "ridge" }) :  
       "The forest grows to the edge of a mountain ridge. "
       "The top of the ridge can not be seen from here.",
  ]) );
  SetItemAdjectives( ([
    "life" : ({ "plant", "tall", "green" }),
    "canopy" : ({ "above", "below" }),
    "path" : ({ "trampled" }),
    "ridge" : ({ "mountain" }),
  ]) );  
  SetInventory( ([
  DAL_NPC "monk_parakeet" : random(2) + random (2) + random (2),
    DAL_NPC "wild_boar" : random(2),
    DAL_OBJ "black_truffle" : random(3),
    DAL_NPC + "monkey" : random(2) + random(2) + random(2),
    DAL_OBJ "r_plant" : 2 + random(3),
  ]) );
  SetListen( ([
    "default" : "Branches creak as parakeets chatter.",
  ]) );
  SetSmell( ([
    "default" : "The air is thick and damp.",
  ]) );
  SetExits( ([
    "north" : DAL_ROOM "3,1.c",
    "west" : DAL_ROOM "2,0.c",
    "south" : DAL_ROOM "3,-1.c",
    "east" : DAL_ROOM "west_gate",
  ]) ); 
  SetEnters( ([
  ]) );
}
