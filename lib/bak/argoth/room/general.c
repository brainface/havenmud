#include <lib.h>
#include "../argoth.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetShort("Argoth General Store");
    SetLong("The Argoth General Store looks a lot like the old Karak Varn "
    "General Store.  The shelves are arranged in a similar fashion, and "
    "the racks and bins holding the goods are made in the same way.  The only "
    "difference is that where the old Karak Varn store used to sell weapons "
    "and armour in addition to mundane goods, this store sells only everyday "
    "items");
  SetDomain("Crystal Reaches");
    SetItems( ([
    ({ "shelves" }) :
    "The shelves sit on the wall holding merchandise.",
    ({ "racks and bins", "racks", "bins"}) :
    "The racks and bins are full of useful things.",
]) );
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd4.c",
]) );
    SetObviousExits("out");
    SetSmell( ([
    "default" : "There is an odor of smoke, leather, and paint.",
]) );
    SetClimate("indoors");
    SetInventory( ([
    ARGOTH_NPC + "vendill.c" : 1,
]) );
    SetAmbientLight(40);
}
