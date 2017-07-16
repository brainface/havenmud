
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
    "The air seems to be slightly warmer in this area of the cave. "
    "The warmth appears to be coming from the north wall, although "
    "nothing else notably distinguishes this wall. Grooves are worn "
    "into all sides of the grey stone cave, created by the slow and "
    "constant action of the ocean water over many years. Scattered across "
    "the ceiling are small bright green dots of lichen which glow "
    "softly, reflecting off the pools of sea water on the floor."
    );
    SetListen(
    "default", "The ocean gently roars somewhere nearby.",
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
    ({ "lichen", "ceiling", "light", "illumination" }) : "Small spots "
    "of bright green lichen dot the ceiling, glowing with a green "
    "light which illuminates the cavern.",
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
    "lichen" : ({ "green", "glowing", "bright", "dots", "small" }),
    "water" : ({ "small", "sea", "ocean" }),
    ]) );
    SetInventory( ([
    NPC+"oceanid.c" : 1,
   ]) );
    SetExits( ([
    "west" : ROOMS+"8,4,-3.c",
    "south" : ROOMS+"9,3,-3.c",
    ]) );
}
