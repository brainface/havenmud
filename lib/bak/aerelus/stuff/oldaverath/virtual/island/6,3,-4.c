
// Ocean Cave
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>
#include <caves.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(30);
    SetClimate("underground");
    SetShort("inside an Ocean Cave");
    SetLong(
    "A thick blanket of dark blue lichen clings to the ceiling in "
    "this part of the cavern, continuing to the east and southeast "
    "where the cave curves away. From the lichen a blue light glows, "
    "lighting the cave in all directions. Scattered across the ground "
    "are dents containing ocean water, which appear to have been "
    "created by the same wearing action which created this entire "
    "complex originally."
    );
    SetListen(
    "default", "A deep rumble vibrates the cave.",
    );
    SetSmell(
    "default", "A salty tang fills the air.",
    );
    SetItems( ([
    ({ "cave", "cavern" }) : (: GetLong :),
    ({ "rock" }) : "Grey rock forms these caves, worn into these shapes "
    "by the constant action of the moving ocean which used to fill this "
    "cavern at high tide then drain away at low tide, carrying away "
    "pieces of the cavern with it.",
    ({ "lichen", "ceiling", "light", "illumination" }) : "A single "
    "coat of dark blue lichen covers the entire visible ceiling, "
    "providing faint illumation.",
    ({ "water", "pool", "pools" }) : "Small pools of sea water have "
    "collected in the uneven pockmarks of the floor of the cave. These "
    "are the reminants of the ocean which used to fill these caves at "
    "high tide.",
    ({ "wall", "walls", "floor", "ground" }) : "All sides of the cave "
    "are formed of pockmarked grey stone which appears to have been worn "
    "away by the constant action of salt water. Ripples are visible on "
    "the walls, all leading in the same direction, seeming to illustrate "
    "the paths which the moving ocean water used when it filled and "
    "retreated from these caves while forming them.",
    ]) );
    SetItemAdjectives( ([
    "rock" : ({ "grey", "worn", "pockmarked" }),
    "lichen" : ({ "blue", "glowing", "blanket", "dark" }),
    "water" : ({ "small", "sea", "ocean" }),
    ]) );
    SetInventory( ([
    NPC+"crab2.c" : 2,
    ]) );
    SetExits( ([
    "east" : ROOMS+"7,3,-4.c",
    "southeast" : ROOMS+"7,2,-4.c",
    ]) );
}
