// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

  static void create() {
  room::create();
  SetShort("The center of Karak");
  SetLong(
    "Two dirt roads come together at this intersection. To the west "
    "the road appears to lead to an open clearing, while to the east and south "
    "there are clusters of the plain wooden buildings typical of Karak. The "
    "area to the east appears to be mostly concerned with commerce. To the "
    "south the buildings are larger and suggest the heart of this community. "
    "Further to the south a rim of blue can be seen, giving color to the "
    "horizon and suggesting the presence of the ocean."
  );
  SetItems( ([
    ({ "intersection", "roads", }) : (: GetLong :),
    ({ "clearing", "west" }) : "To the west there is a lack of buildings, "
    "resulting in a clearing near the town of Karak.",
    ({ "buildings", "cluster" }) : "Groups of buildings stand to the south "
    "and east, all made of the same simple yet strong wooden construction. "
    "Those to the east appear to be shops while to the south lies the main "
    "part of Karak.",
    ({ "ocean", "blue", "horizon" }) : "A rim of blue rides the southern "
    "horizon, suggesting the presence of the ocean further south, beyond "
    "the main part of Karak.",
  ]) );
  SetItemAdjectives( ([
    "buildings" : ({ "cluster", "of", "south", "east", "karak", "wooden" }),
    "ocean" : ({ "blue", "rim", "color" }),
  ]) );
  SetSmell( ([
    "default" : "The odor of sweat and dirt is strong here.",
  ]) );
  SetListen( ([
    "default" : "The sounds of various activities come from the south and "
    "east, while to the west silence reigns.",
  ]) );
  SetInventory( ([
    KARAK_OBJ + "fountain" : 1,
    KARAK_NPC + "equipper" : 1,
    KARAK_NPC + "citizen" : 2,
    KARAK_NPC + "guard" : 2,
    KARAK_NPC + "controller" : 1,
  ]) );
  SetExits( ([
    "north" : KARAK_ROOM + "rd2",
    "south" : KARAK_ROOM + "rd5",
    "east"  : KARAK_ROOM + "rd4",
    "west"  : KARAK_ROOM + "clearing",
  ]) );
}
