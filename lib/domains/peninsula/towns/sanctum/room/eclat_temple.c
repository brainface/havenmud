// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../rome.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetWarmth(40);
  SetExits( ([
    "out" : ROME_ROOM "rd09",
    ]) );
  SetShort("inside the Eclat Temple");
  SetLong("The Eclat Temple is a small and friendly building of "
          "all white marble. Lofty ceilings raise above to the "
          "center of the room, where a peak seems to be met. "
          "Large windows of expensive glass look out over the "
          "city, trimmed in gold to reflect the light in ways "
          "which make the temple seem to glory with its glory.");
  SetReligion("Eclat");
  SetSmell( ([
    "default" : "The temple maintains a flowery smell year round.",
    ]) );
  SetListen( ([
    "default" : "Oddly, there is a faint sound of birds chirping.",
    ]) );
  SetInventory( ([
    ROME_NPC "annika" : 1,
    ]) );
}
