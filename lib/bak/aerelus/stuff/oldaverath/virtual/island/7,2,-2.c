
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
    "Years of slow action by the ocean water have worn caves through "
    "the grey rock, caves which lead away to the east and northwest from "
    "here. Many dips occur in the floor and small puddles of ocean "
    "water have collected there. Irregularties in the ceiling support "
    "patchy colonies of green lichen, which glow faintly and illuminate "
    "the cavern."
    );
    SetListen(
    "default" , "The ocean gently roars somewhere nearby.",
    );
    SetSmell(
    "default" , "A salty tang fills the air.",
    );
    SetItems( ([
    ({ "cave", "caves" }) : (: GetLong :),
    ({ "rock" }) : "Grey rock forms these caves, worn into these shapes "
    "by the constant action of the moving ocean which used to fill this "
    "cavern at high tide then drain away at low tide, carrying away "
    "pieces of the cavern with it.",
    ({ "lichen", "ceiling", "light", "illumination" }) : "Lichen coats "
    "the ceiling in large, irregular patches which glow green and "
    "illuminate the cave.",
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
    NPC+"sea_urchin.c.c" : 3,
    ]) );
    SetExits( ([
    "east" : ROOMS+"8,2,-2.c",
    "northwest" : ROOMS+"6,3,-2.c"
    ]) );
}
