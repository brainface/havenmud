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
    "out" : ROME_ROOM "rd04",
    ]) );
  SetShort("inside the Soirin Temple");
  SetSmell( ([
    "default" : "A faint oily smell fills the air.",
    ]) );
  SetListen( ([
    "default" : "The temple seems to quietly whisper to itself.",
    ]) );
  SetLong("The Soirin Temple is decorated in black marble and obsidian, "
         "with thin lines of gold trim making the temple's blackness "
         "seem oddly darker. Around the room, dark candles slightly "
         "illuminate the dimness, making the room have a faintly "
         "foreboding feeling.");
  SetReligion("Soirin");
  SetInventory( ([
/*
    ROME_NPC "t_soirin" : 1,
*/
    ROME_NPC "m_soirin" : 1,
    ]) );
}
