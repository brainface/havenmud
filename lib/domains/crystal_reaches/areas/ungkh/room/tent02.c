//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("inside a dark tent");
  SetClimate("indoors");
  SetLong(
    "The inside of this tent is hazy and dark. It appears the ogres who live "
    "within own many weapons, as evidenced by the rusty piles of metal "
    "lying on the floor. The walls here are made of what appears to be "
    "dwarf skins, lashed together without being cured. The only exit is "
    "back out of the tent flap."
  );
  SetSmell("The tent smells like a rusty kettle.");
  SetListen("The noise of Ungkh is greatly reduced inside the tent.");
  SetItems( ([
    ({"hides", "tent", "walls"}) :
    "The hides that make this tent are the skins of dwarves. The veins and "
    "insulating bits of fat still cling to the skins.",
    ({"weapons", "weapon", "pile", "piles" "metal", "floor"}) :
    "The floor is covered with old, rusty implements of battle.",
  ]) );
  SetItemAdjectives( ([
    "piles" : ({ "rusty" }),
  ]) );
  SetExits( ([
    "out" : U_ROOM + "road03",
    ]) );
  SetInventory( ([
    U_NPC "bluntogre" : 3,
  ]) );
  }
