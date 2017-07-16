//-- Torak@Haven --//
//--    Ungkh    --//
//--   7/17/99   --//

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Crystal Reaches");
  SetTown("Ungkh");
  SetShort("the pit");
  SetLong(
    "A large pit has been built here, serving as "
    "the cemetery of Ungkh.  Kuthar do not bury "
    "the cadavers of their dead, as the soul is "
    "the only thing of worth."
    );
  SetSmell( ([
    "default" : 
    "Death hangs in the air.",
    ]) );
  SetListen( ([
    "default" :
    "Moans of pain echo across the land.",
    ]) );
  SetItems( ([
    ({ "pit" }) :
       "The pit is well over twenty feet across, and "
       "its depth is undetectable with the amount of "
       "dead in it.",
    ({ "dead", "corpses" }) :
       "The pit holds the corpses of many dead.",
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetEnters( ([
    ]) );
  SetInventory( ([
    U_NPC + "flink_shaman" : 1,
// Commented out deathguard since they were guarding nothing of a dead god.
//     U_NPC + "deathguard" : 2,
    U_NPC + "gorfla" : 1,
    U_NPC + "mmk_nojoin_shaman" : 1,
    ]) );
  SetExits( ([
    "west" : U_ROOM + "hospital",
    ]) );
  }
