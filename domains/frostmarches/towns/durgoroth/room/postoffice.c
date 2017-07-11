#include <lib.h>
#include "../durgoroth.h"

inherit LIB_POST_OFFICE;

static void create() {
   post_office::create();
   SetClimate("sub_arctic");
   SetTown("Durgoroth");
   SetShort("wreckage of a post office");
   SetLong("Theroof of this building seems destroyed in the "
     "original catastrophe ruined the town, as no trace of it "
     "remains. Ancient, crumpled letters and scrolls coat the "
     "floor in a thick layer of moldy parchment, made slick "
     "by invading rain and sleet over the years. A solid doorframe "
     "has somehow survived the abuse of the years and leads out to "
     "the east.\n This room is _totally_ out-of-character. "
     " Use the <mail> command to enter the mudwide mail system.");
   SetItems( ([
     ({"letters","scrolls","parchment","rain","sleet","doorframe"}) :
       "Maybe you should just type 'mail'.",
   ]) );
   SetExits( ([
      "out" : DURG_ROOM "/road05",
   ]) );
   SetInventory( ([
   ]) );
}

