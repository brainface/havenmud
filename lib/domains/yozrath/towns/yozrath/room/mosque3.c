// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../yozrath.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetShort("the Sanctuary of the Prophets in the Mosque of Yozrath");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "west" : YOZRATH_ROOM "mosque1",
    ]) );
  SetInventory( ([
    YOZRATH_NPC "imam" : 1,
    ]) );
  SetReligion("Kylin", "Desert Kylin");
  SetLong(
    "The Sanctuary of the Prophets is a large hall that is filled almost entirely "
    "with prayer mats. Braziers of incense fill the air with a pungent but pleasant "
    "smoke. The stone walls of the Sanctuary are plain and unadorned, keeping with "
    "the spartan traditions of Desert Kylin. To the west lies the entrance to the "
    "Mosque and the base of the minaret."
    );
  SetItems( ([
    ({ "mat", "mats" }) : "Prayer mats are arranged for the comfort of the supplicants.",
    ({ "wall", "walls" }) : "The walls of the Mosque are plain and unadorned.",
    ({ "brazier", "braziers" }) : "Braziers fill the air with a pungent incense.",
    ]) );
  SetSmell("Smoky incense fills the air from the braziers.");
  SetListen("The calls of the imams bring the faithful to worship.");
}
