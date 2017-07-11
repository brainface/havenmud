#include "../wood.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : HWD_ROOM "/gelf3",
    "north": HWD_ROOM "/gelf5",
    "south": HWD_ROOM "/gelf6",
    ]) );
  SetShort("in the Havenwood");
  SetLong(
    "The path along the outer rim of the clearing continues to the south and west. "
    "Directly to the north is a small area set aside for the Elders of the "
    "wild-elves to meet. A hollowed out tree trunk here bears the marks of the "
    "Nightrevellers, the leaders of the elven musical festivities."
    );
  SetSmell("The forest smell is strong and calming here.");
  SetListen("The sounds of merriment come from the tree.");
  SetItems( ([
    ({ "trunk", "tree" }) : "This hollowed out tree trunk is the home of the Nightrevellers.",
    ]) );
  SetEnters( ([
    "trunk" : HWD_ROOM "/music",
    ]) );
  SetInventory( ([
    HWD_NPC "/fendell" : 1,
    ]) );
}