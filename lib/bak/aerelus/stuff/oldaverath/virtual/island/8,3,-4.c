
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
    "The cavern makes a sharp turn here, leading away to the "
    "northeast and southeast, faint ripples decorating both "
    "walls. These marks seem to have been caused by the incessant "
    "action of ocean water over many years; the same action which "
    "created these caverns. Illumination is given by a blanket of "
    "dark blue lichen which covers the ceiling and glows a faint "
    "blue color. Pools of ocean water containing various marine "
    "life litter the floor, also created by the action of the ocean "
    "water."
    
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
    NPC+"hermit_crab2.c" : 3,
    ]) );
    SetExits( ([
    "northeast" : ROOMS+"9,4,-4.c",
    "southeast" : ROOMS+"9,2,-4.c",
    ]) );
}
