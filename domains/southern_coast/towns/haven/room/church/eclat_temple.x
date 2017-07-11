#include <lib.h>
#include "../haven.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetWarmth(40);
  SetExits( ([
    "out" : H_ROOM "holy_path/hp3",
    ]) );
  SetShort("inside the Eclat Temple");
  SetLong("The Eclat Temple is a small and friendly building of "
          "all white marble. Lofty ceilings raise above to the "
          "center of the room, where a peak seems to be met. "
          "Large windows of expensive glass look out over the "
          "city, trimmed in gold to reflect the light in ways "
          "which make the temple seem to glow within its glory.");
  SetSmell( ([
    "default" : "The temple maintains a flowery smell year round.",
    ]) );
  SetListen( ([
    "default" : "Oddly, there is a faint sound of birds chirping.",
    ]) );
  SetInventory( ([
    H_NPC "eclat_suvraela" : 1,
    H_NPC "eclat_sindara" : 1,
    ]) );
}
