// Coded by Zeratul 11-27-99
#include <lib.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetDomain("Estergrym");
  SetClimate("temperate");
  SetShort("On a hidden path");
  SetDayLong("The trees loom down over the small path, blocking the "
     "sun as it beats down on the land. Dense wildlife roams about the "
     "area, without any signs of buildings, but a thick forest of "
    "mountainous trees loom about. "
     );
  SetNightLong("The trees loom down over the small path, blocking the "
     "moon as it shines down on the land. Dense wildlife roams about the "
     "area, without any signs of buildings, but a thick forest of "
     "mountainous trees loom about. "
     );
  SetListen( ([
     "default" : "Rustling and chirping of animals can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The air smells cool and fresh.",
     ]) );
  SetItems( ([
     ({"forest","trees"}) : "These big trees look like giant mothers "
     "protecting their children as they loom over the plantlife and "
     "provide shade to the surrounding area. ",
     ({"path","small path"}) : (: GetLong :),
     ]) );
  SetItemAdjectives( ([
     "trees" : ({"large","mother like ","protectives"}),
     "path" : ({"small","hidden"}),
     ]) ),
  SetInventory( ([
     ]) );
  SetExits( ([
     "west" : LAKE_ROOM + "/lake5",
     "northeast" : LAKE_ROOM + "/path2",
     ]) );
}
