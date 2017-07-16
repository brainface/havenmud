#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : GUROV_ROOM "cr7",
    ]) );
  SetShort("the Gurov Cemetery outside of the Cathedral");
  SetLong(
    "Lying in the courtyard of the Cathedral of Three Gods is this quiet "
    "cemetery. Though the cemetery speaks to death, it does not seem "
    "to be in any way evil. Tombstones and crypts are spread around "
    "the cemetery in an orderly fashion, each depicting the life and "
    "exploits of various former citizens of the Principality. The "
    "Cathedral rises into the sky, its onion domes and spires "
    "seeking to showcase the glory of the faiths and their history."
    );
  SetItems( ([
    ({ "tomb", "tombstone", "crypt", "stone" }) : 
           "The graves mark the passing "
           "of the nobles and peasants of the Principality of Gurov.",
    ({ "dome", "domes", "spire", "spires" }) : "The onion domes and "
           "spires of the Cathedral showcase the glory of the three "
           "Greater Gods.",
    "cathedral" : "The Cathedral of Three Gods in Gurov is a spectacular "
                  "building of vaulted, onion domes and spires that "
                  "ascend to the heavens.",
    ]) );
  SetItemAdjectives( ([
    "dome" : ({ "onion", "vaulted", }),
    "tomb" : ({ "stone", "tomb" }),
    ]) );
  SetSmell("The smell of freshly turned earth gives the cemetery a chill feeling.");
  SetListen("While the cemetery is quiet, chanting can be heard from the Cathedral.");
  SetEnters( ([
    "cathedral" : GUROV_ROOM "cathedral3",
    ]) );
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
    GUROV_NPC "healer" : 1,
    ]) );
}
