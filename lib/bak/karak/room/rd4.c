#include <lib.h>
#include <domains.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Ahriman's Passage");

  SetDayLong(
    "Ahriman's Passage runs east to west here, forming a "
    "passage through Karak-Varn. To the east the cobbled "
    "street widens slightly, forming the center of town. "
    "To the east the spier of the Church of Ahriman rises, "
    "and the squat Town Headquarters are visible. "
    "To the west is the Post Office and the main Trading Post. "
  );
  SetNightLong(
    "To the west the cobbled road widens into the town square "
    "of Karak-Varn. All is shrouded in the blanket of night, "
    "broken only by soft candlelight from the east, and a torch "
    "points that lights a shop to the west."
  );
  SetItems( ([
    ({ "street" }) :
      (: GetLong() :),
    ({ "torch", "dark street", "dark cobbled street" }) :
      (: GetNightLong() :),
    ({ "church", "of Ahriman" }) :
      "The spier of the Church of Ahriman rises to the east.",
    "headquarters" :
      "The squat building to the east is the Town Headquarters.",
    "office" :
      "The town post office stands to the west.",
    "post" :
      "Karak-Varn's main Trading Post lies to the west.",
  ]) );
  SetItemAdjectives( ([
    "church" : ({ "Ahriman's", "of Ahriman" }),
    "street" : ({ "cobbled" }),
    "office" : ({ "post", "town", "Karak-Varn" }),
    "post" : ({ "trading", "town", "Karak-Varn" }),
  ]) );
  SetExits( ([
    "east" : K_ROOM + "/rd3",
    "west" : K_ROOM + "/rd5",
    "south" : CRYSTAL_REACHES_TOWNS "argoth/room/clearing",
  ]) );
}
