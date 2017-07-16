#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

int KylinExit();

static void create() {
  ::create();
  SetShort("inside the Mosque of Yozrath");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "out"  : YOZRATH_ROOM "mos3",
    "east" : YOZRATH_ROOM "mosque3",
    "south": YOZRATH_ROOM "mosque4",
    ]) );
  AddExit("north", YOZRATH_ROOM "mosque2", (: KylinExit :) );
  SetLong(
    "The entrance to the Mosque of Yozrath is a very stoic construction. "
    "Brown sandstone walls are neatly maintained with a smooth, nearly "
    "polished floor. The entranceway is devoid of the normal trappings that "
    "litter most Kylin Cathedrals owing to the spartan nature of the desert "
    "sect. While most Kylin churchs line their halls in gold and the glory "
    "of Duuktsaryth the Lord of Order, the desert sect takes a more quiet "
    "and reserved view of He Who Judges. To the east lies the sanctuary, "
    "where the Supreme Imam performs the rituals of the faith. To the south "
    "lies the base of the minaret. To the north is a quiet room for the faithful."
    );
  SetSmell("Incense burns from braziers arranged around the entrance.");
  SetListen("Chants quietly echo down the hallways.");
  SetItems( ([
    ({ "brazier", "braziers" }) : "The braziers hold incense that burns night and day.",
    "floor" : "The floor is a polished sandstone.",
    ({ "wall", "walls" }) : "The walls are smooth and lack any special markings.",
    ]) );
}

int KylinExit() {
  object who = this_player();
  if (who->GetReligion() != "Kylin") {
    who->eventPrint("You get the strangest feeling that you shouldn't enter that room.");
    return 0;
  }
  who->eventPrint("You are welcomed to the repose of He Who Judges.");
  return 1;
}
