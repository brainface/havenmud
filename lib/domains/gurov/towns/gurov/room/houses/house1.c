#include <lib.h>
#include "../../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a dirty hovel");
  SetLong(
    "This house has seen better days.  The wood flooring has seen some rot. "
    "The walls are starting to receive the attention of various molds. "
    "There are some furnishings in the small hovel, but their use is "
    "precluded due to the smell coming off everything in the house."
    );
  SetItems( ([
    ({ "furniture", "furnishings" }) : "The furniture is rotting and smells "
           "vaguely of sweat and mold.",
    ({ "wall", "walls" }) : "The walls are begging to mold.",
    ({ "floor", "flooring" }) : "The floor is starting to rot.",
    ]) );
  SetSmell("There is a stench of rot and decay here.");
  SetListen("Something scurries about under the floor.");
  SetInventory( ([
    GUROV_NPC "mold" : 1,
    ]) );
  SetExits( ([
    "out" : GUROV_ROOM "alley1",
    ]) );
}