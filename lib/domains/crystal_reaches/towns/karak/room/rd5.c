// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Karak Road");
  SetLong(
    "Sturdy wooden buildings stand on both sides of the road, as well as "
    "to the south. While simple in construction, they are well-built and "
    "appear designed to endure decades of use. The building to the east seems "
    "to be the town post office while that to the west is slightly larger "
    "and bears an elaborately carved device of an axe splitting a rock. It "
    "appears to be the headquarters of the local chief."
  );
  SetItems( ([
    ({ "buildings" }) : "The wooden buildings of Karak line both sides "
    "of the road, both here and to the south.",
    ({ "office", "building" }) : "The plain wooden building to the east "
    "appears to be the town post office.",
    ({ "hall", "building", "headquarters" }) : "The larger building on "
    "the west side of the road has a decorative carving above its "
    "entrance, suggesting it is the headquarters of the local chief.",
    ({ "device", "carving" }) : "A elaborate carving above the entrance "
    "to the western building depicts an axe splitting a rock in half. "
    "This symbol is a traditional depiction of how the orcs see themselves, "
    "as the axe which will split asunder all of their enemies."
  ]) );
  SetItemAdjectives( ([
    "buildings" : ({ "sturdy", "wooden", "well-built", "simple" }),
    "office" : ({ "east", "post", "town" }),
    "hall" : ({ "west", "larger", "town", "local" }),
    "device" : ({ "elaborate", "elaborately", "carved" }),
  ]) );
  SetSmell( ([
    "default" : "A faint mist of dirt hangs in the air, stirred up from the "
    "road.",
  ]) );
  SetListen( ([
    "default" : "The roar of the sea can be heard very faintly to the south.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "citizen" : 2,
    KARAK_NPC + "guard" : 2,
  ]) );
  SetExits( ([
    "north" : KARAK_ROOM + "rd3",
    "south" : KARAK_ROOM + "rd6",
  ]) );
  SetEnters( ([
    "office" : KARAK_ROOM + "post_off",
    "hall"   : KARAK_ROOM + "town_hall",
  ]) );
}
