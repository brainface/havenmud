#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Hall of Janissaries");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "out" : YOZRATH_ROOM "mos2",
    ]) );
  SetLong(
    "The Hall of Janissaries is a thick stone structure that houses the "
    "army of the desert and trains new recruits in the combat skills that "
    "are so important to the life of a warrior. Various banners and badges "
    "line the walls showing the martial traditions of the desert forces, "
    "all while showing the proper dedications to He Who Judges."
    );
  SetItems( ([
    ({ "banner", "banners", "badge", "badges" }) : "The banners and badges "
        "are detailed and well-woven standards of the units of the army.",
    ]) );
  SetInventory( ([
    YOZRATH_NPC "janissary" : 1,
    YOZRATH_NPC "trainer"   : 1,
    ]) );
  SetListen("The clang of weapons training echoes from the walls.");
}
