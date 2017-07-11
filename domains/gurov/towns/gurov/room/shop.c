#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside the General Store");
  SetLong(
    "The Gurov General Store is a cramped building that houses many "
    "articles of interest to the public.  From torches and matches "
    "to fishing poles, the store sells many things that many people "
    "would want. A large oak counter dominates the room."
    );
  SetSmell("The store has a faint smell of lamp oil.");
  SetListen("The store has a friendly quiet to it.");
  SetInventory( ([
    GUROV_NPC "shopkeep" : 1,
    STD_OBJ "lootchest" : 1,
    ]) );
  SetExits( ([
    "out"  : GUROV_ROOM "cr5",
    ]) );
}
