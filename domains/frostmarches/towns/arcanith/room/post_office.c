#include <lib.h>
#include "../ruins.h"

inherit LIB_POST_OFFICE;

static void create() {
   post_office::create();
   SetClimate("indoors");
   SetAmbientLight(50);
   SetTown("Arcanith");
   SetShort("a mail shack");
   SetLong("This small shack, slightly larger than an outhouse, holds "
     "the few letters and correspondance arriving for the scavengers of "
     "the ruins. The room is devoid of anything that could even vaguely "
     "be considered useful.  This room is _totally_ out-of-character. "
     " Use the <mail> command to enter the mudwide mail system.");
   SetItems( ([
     ({"letters","letter","correspondance","record"}) :
       "Maybe you should just type 'mail'.",
   ]) );
   SetExits( ([
      "out" : ROOM "/ruins3",
   ]) );
   SetInventory( ([
   ]) );
}

