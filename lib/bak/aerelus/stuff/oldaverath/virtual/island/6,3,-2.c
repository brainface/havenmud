
// Ocean Cave
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>
#include <caves.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(25);
    SetClimate("underground");
    SetShort("inside an Ocean Cave");
    SetLong(
    "A moderate-size pool of ocean water fills the center of a sharp bend "
    "in the cave. Here the cave trails off to the east and southeast, causing "
    "the pool to be surrounded almost completely by the walls of the cave. "
    "This single deep basin appears to have been caused by the wearing action "
    "of the salt water constantly dripping from the lichen which coats the "
    "ceiling. The moisture clinging to it makes the glowing of the lichen "
    "slightly dimmer than in the surrounding areas."
    );
    SetListen(
    "default", "A steady, constant dripping echos through the cave.",
    );
    SetSmell(
    "default", "A salty tang fills the air.",
    );
    SetItems( ([
    ({ "cave", "caves" }) : (: GetLong :),
    ({ "rock" }) : "Grey rock forms these caves, worn into these shapes "
    "by the constant action of the moving ocean which used to fill this "
    "cavern at high tide then drain away at low tide, carrying away "
    "pieces of the cavern with it.",
    ({ "lichen", "ceiling", "light", "illumination" }) : "Lichen coats "
    "the ceiling in large, irregular patches which glow green and "
    "illuminate the cave. Water saturates the lichen here, occasionally "
    "dripping down into the pool below.",
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
    "lichen" : ({ "green", "glowing" }),
    "water" : ({ "small", "sea", "ocean" }),
    ]) );
    SetInventory( ([
    NPC+"mussel.c" : 5,
    ]) );
    SetExits( ([
    "east" : ROOMS+"7,3,-2.c",
    "southeast" : ROOMS+"7,2,-2.c",
    ]) );
}
