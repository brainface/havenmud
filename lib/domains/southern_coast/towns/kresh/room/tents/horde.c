#include <lib.h>
#include "../../goblins.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetProperty("no attack", 1);
  SetProperty("no magic", 1);
  SetNewsgroups( ({ "guild.horde" }) );
  SetShort("inside the Tent of the Horde");
  SetLong(
    "This tent is sparsely furnished but is still impressive. Its heavy "
    "brown outside is also magically protected as a safe place for the "
    "members of the Horde to gather and plan their domination of Kailie. "
    "Arranged around the tent are various cushions for the members of "
    "the horde to relax and rest for a while."
    );
  SetItems( ([
    ({ "cushion", "cushions" }) : "These cushions look very comfortable.",
    ]) );
  SetExits( ([
    "out" : GOBLIN_ROOM "m_5",
    ]) );
}
