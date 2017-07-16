// Coded by Zeratul 11-28-99
#include <lib.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetDomain("Estergrym");
  SetClimate("temperate");
  SetShort("a road inside the estergrym mountains");
  SetLong("This small cobblestone travels up the Estergrym Mountains. "
     "The terrain here seems a bit unstable and makes walking a bit "
     "dangerous. The small road here continues up the mountains, "
     "while down leads back to the Estergrym Road. "
     );
  SetItems( ([
     ({ "road","cobblestone road" }) : "This small cobblestone "
     "road heads up and down the mountains. ",
     ({ "mountains", "estergrym mountains" }) : "This mountain "
     "is in the north eastern part of the world.",
     ({"terrain"}) : "The terrain here is very rough and unstable.",
     ]) );
  SetExits( ([
     "down" : LAKE_ROOM "/road2",
     "up" : LAKE_ROOM "/road4",
     ]) );
}
