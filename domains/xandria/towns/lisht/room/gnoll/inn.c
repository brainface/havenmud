//Selket@Haven
//2006
#include <lib.h>
#include <std.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Common Room of the Blue Lotus Inn");
   SetClimate("indoors");
   SetAmbientLight(45);
   SetObviousExits("out, up");
   SetExits( ([
      "out" : LISHT_ROOM "gnoll/wr1",
      "up" : LISHT_ROOM "gnoll/inn2",
   ]) );
   SetLong("This is a lively inn, where many citizens of Lisht "
           "come to eat together or drink their cares away. The "
           "place is mostly clean, and the tables and chairs are "
           "well-worn but polished brightly. The walls are hung "
           "with bright tapestries that are only a little stained "
           "with the passage of time in an inn full of gnolls. "
           "Upstairs above the din is a small bedroom."
    );
   SetSmell( ([
      "default" : "The room smells of good food and cheap beer.",
   ]) );
   SetListen( ([ 
      "default" : "The room is a fury of clattering and chatter.",
   ]) );
   SetItems( ([
      ({ "inn", "establishment" }) :
         (: GetLong :),
      ({ "table", "tables", "bench", "benches", "furniture" }) :
         "The furniture is crumb-free and well waxed.",
      ({ "floor", "floors" }) :
         "The floor is fairly clean, if a bit sandy.",
      ({ "stairs" }) :
         "These stairs lead up into the bedroom.",
      ({ "tapestries", "tapestry", "wall", "walls" }) :
         "The tapestries on the walls are mostly abstract "
         "designs that vaguely remind the onlooker of lewd "
         "acts.",
   ]) );
   SetItemAdjectives( ([
      "stairs" : ({ "set of" }),
      "room" : ({ "common", "sleeping" }),
   ]) );
   SetInventory( ([
      LISHT_NPC   + "hathor" : 1,
      LISHT_NPC   + "patron" : 3,
    LISHT_NPC + "drunk" : 3,
   ]) );
}
