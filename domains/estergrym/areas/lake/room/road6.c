// Coded by Zeratul 11-28-99
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a road down the Estergrym Mountains");
  SetLong("This small cobblestone road travels down the Estergrym Mountains. "
     "The terrain here seems a bit unstable and makes walking a bit "
     "dangerous. The small road here continues north into the mountains "
    "and southwest to the Grymxoria Road."
     );
  SetItems( ([
     ({ "road","cobblestone road" }) : "This small cobblestone "
     "road heads up and down the mountains. ",
     ({ "mountains", "estergrym mountains" }) : "This mountain "
     "is in the north eastern part of the world.",
     ({"terrain"}) : "The terrain here is very rough and unstable.",
     ]) );
  SetExits( ([
     "southwest"  : ESTERGRYM_VIRTUAL "grymxoria_road/40,0",
     "north" : LAKE_ROOM + "/lake1",
     ]) );
}
