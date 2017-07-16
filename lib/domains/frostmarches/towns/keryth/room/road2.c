//coded by Syra 12/97
//taken over by Zedd 12/98

#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetShort("Along a road in Keryth");
  SetTown("Keryth");
  SetLong("The path weaves between the snow covered buildings and ambles to "
          "the northwest and south.  To either side of this road stand the "
          "buildings in which the Keryth General Store and the town bank "
          "reside.  Looming gently in the far distance, a mountain range "
          "watches the town of Keryth.");
  SetItems( ([
    ({ "town", "path", "road" }) : (:GetLong:),
    ({ "snow covered buildings", "snow buildings", "buildings", "snow" }) :
       "The snow blankets the surrounding buildings.",
    ({ "keryth general store", "general store", "store", "keryth store",
       "nice trustworthy establishment", "building", "nice establishment",
       "establishment" }) :
       "The Keryth General store is the only place to buy anything in town, "
       "save the tavern. From the outside, it looks like a nice, trustworthy "
       "establishment.",
    "tavern" :
       "The tavern is northwest of here.",
    ({ "keryth bank", "bank", "building" }) : 
       "The Keryth bank stands here. It is known for having unusual "
       "currencies."
  ]) );
  SetExits( ([
    "northwest" : K_ROOM + "/road3",
    "south"     : K_ROOM + "/road1"
  ]) );
  SetEnters( ([
    "bank" : K_ROOM + "/bank.c",
    "general store" : K_ROOM + "/gstore.c"
  ]) );
  SetListen( ([ "default" : "A cold wind whistles here." ]) );
  SetInventory( ([ K_OBJ + "/fountain.c" : 1,
                   K_NPC + "/citizen" : random(3)+1,
                   K_NPC + "/equipper" : 1,
  ]) );
}
