#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;
    static void create() {
    room::create();
    SetShort("The main crossroads of Argoth");
    SetLong("The two roads of Argoth come together at this intersection.  To "
    "the west, the road leads to a building which is still under construction, "
    "and to the east is the main retail area of the city.  The main road "
    "leads north towards the ruins of Karak Varn, and south to the town hall, "
    "church, and bank of the city.  The back end of a building whose entrance "
    "is to the east is a few feet from the roadside.");
  SetDomain("Crystal Reaches");
    SetItems( ([
    ({ "two roads of argoth", "two roads", "roads" }) :
    "The two roads of Argoth are made of a dark cobblestone and lead to the "
    "important areas of the town.",
    ({ "building" }) :
    "The building is large and made of a deep red brick.",
    ({ "intersection" }) :
    "This intersection is one of the busiest places in town.",
    ({ "building" }) :
    "The building appears to be an inn.",
    ({ "karak varn", "ruins" }) :
    "The ruins of Karak Varn remain as a grim reminder of the determination "
    "of the orcs which populate this town.",
    ({ "town hall" }) :
    "The town hall can be seen at the end of the road, its enormous spires "
    "reaching for the sky.",
    ({ "church" }) :
    "The church of Saahagoth sits next to the town hall, and is almost as large.",
    ({ "bank" }) :
    "The bank is where the inhabitants of the city go to find a safer place for "
    "their money.",
]) );
    SetExits( ([
    "west" : ARGOTH_ROOM + "rd5.c",
    "east" : ARGOTH_ROOM + "rd3.c",
    "north" : ARGOTH_ROOM + "rd1.c",
    "south" : ARGOTH_ROOM + "rd6.c",
]) );
    SetObviousExits("north, south, east, west");
    SetSmell( ([
    "default" : "The odor of sweat and dirt is strong here.",
]) );
    SetListen( ([
    "default" : "The sounds of construction and feet on the road can be heard.",
]) );
    SetInventory( ([
    ARGOTH_OBJ + "fountain.c" : 1,
    ARGOTH_NPC + "citizen.c" : 1,
    ARGOTH_NPC + "guard.c" : 1,
    ARGOTH_NPC + "soldier.c" : 2,
    ARGOTH_NPC + "citizen2.c" : 1,
]) );
}
