#include <lib.h>
#include "../yozrath.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetShort("a large oasis in the City of Yozrath");
  SetExits( ([
    "north" : YOZRATH_ROOM "oasis5",
    "south" : YOZRATH_ROOM "oasis2",
    "east"  : YOZRATH_ROOM "oasis1",
    "west"  : YOZRATH_ROOM "oasis4",
    ]) );
  SetClimate("arid");
  SetLong(
    "The center of the Yozrath Oasis is the basis for the city itself. "
    "The deep waters of the oasis are traditionally thought to be runoff "
    "from the River Bjorn far to the north and fed through an underground "
    "lake. Palm trees heavy with dates are spread evenly around the oasis, "
    "a testament to the length of time the area has been settled. To the "
    "west lies the palace of the Sheik of the Desert. Lying to the north "
    "is a quiet repose to pray for the souls of those lost in the desert. "
    "To the east lies a path back into the city itself."
    );
  SetItems( ([
    ({ "tree", "trees" }) : "Large palm trees line the oasis, heavy with "
                            "dates that occasionally fall from the tree.",
    ({ "palace" })  : "The palace lies to the west, its imposing stone "
                      "edifice a structure of beauty in the desert.",
    ]) );
  SetItemAdjectives( ([
    "tree" : ({ "palm" }),
    "palace" : ({ "sheik", "sheik's" }),
    ]) );
  SetSpeed(5);
  SetFish( ([
    ]) );
  SetChance(25);
  SetMaxFishing(3);
  SetSmell("A faintly fishy smell comes from the oasis.");
  SetListen("A light breeze rustles through the palm trees.");
  SetInventory( ([
    YOZRATH_OBJ "date" : 2,
    YOZRATH_OBJ "oasis" : 1,
    ]) );
}

void heart_beat() {
  object date;
  object *dates = ({});
  ::heart_beat();
  foreach(object ob in all_inventory()) {
    if (base_name(ob) == YOZRATH_OBJ "date") dates += ({ ob }); 
    }
  if (sizeof(dates) > 10) return;
  if (!random(20)) {
      date = new(YOZRATH_OBJ "date");
      if (!date) return;
      eventPrint("With a thump, a date falls from a tree.");
      date->eventMove(this_object());
  }
}

    
    
    
