#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the forlorn crypt");

  SetClimate("indoors");
  SetAmbientLight(35);

  SetLong(
    "This is an ancient crypt filled with the decaying and withered skeletons "
    "of long-dead Parvans. Niches nestled in the earthen walls hold cobweb-enshrouded "
    "corpses, and lines of mossy coffins sealed in lead cover the slightly dampened floor. "
    "Peeking through the walls and ceiling are the roots of the trees standing above, "
    "hanging into the crypt as if sucking the last vestiges of souls from the decaying occupants."
    );
  SetSmell("Dust mixes with the smell of old death to form an unpleasant atmosphere.");
  SetListen("A faint echo of dripping water ruins the silence.");
  SetItems( ([
    ({ "skeletons", "dead", "parvans", "corpses" }) : "The remains of some very dead Parvans are interred here in the crypt.",
    ({ "niches", "coffins" }) : "The coffins and niches hold the dead within.",
    ({ "walls", "ceiling", "roots" }) : "Roots, seeming much like veins, interlace the dirt walls and ceiling of the crypt.",
    "floor" : "The floor is dampened by rainwater that falls into the crypt.",
    "lead" : "Silvery beads of lead seal the coffins tightly, to keep thieves out and zombies in.",
    ]) );
  SetItemAdjectives( ([
    "skeletons" : ({ "decaying", "withered", "long", "dead", "cobweb", "enshrouded", }),
    "floor" : ({ "earthen" }),
    "niches" : ({ "mossy", }),
    ]) );
  SetInventory( ([
    PARVA_NPC "necro" : 1,
    PARVA_NPC "eustice" : 1,
    ]) );
  SetExits( ([
    "out" : PARVA_ROOM "path8",
    ]) );
}

