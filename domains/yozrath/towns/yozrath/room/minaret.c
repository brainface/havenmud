#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "down" : YOZRATH_ROOM "mosque4",
    ]) );
  SetShort("atop the minaret in the Yozrath Mosque");
  SetLong(
    "The spire of the minaret attached the Mosque of Yozrath is a large "
    "and open affair. From here, imams call the faithful to worship during "
    "daily prayers. Windows open and overlook the courtyard in front of the "
    "Mosque, allowing an interesting view."
    );
  SetSmell("Incense wafts in even here from the Mosque.");
  SetListen("The sounds of the city drift in from the windows.");
  SetItems( ([
    "window" : (: GetRemoteDescription, YOZRATH_ROOM "mos3" :),
    ]) );
}
