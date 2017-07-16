
// Ocean Cave
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>
#include <caves.h>

inherit LIB_ROOM;

int CheckWander();

static void create() {
    room::create();
    SetAmbientLight(30);
    SetClimate("underground");
    SetShort("inside an Ocean Cave");
    SetLong(
    "Grey stone forms all sides of this cave, rippled faintly through the "
    "constant action over time of the ocean water wearing away the stone "
    "and creating these caves. From here the cave twists away to the east "
    "and west, curving downward slightly. Salt tinges the air from the many "
    "pools which spot the floor. A faint green glow comes from the ceiling "
    "and is reflected back by the pools of water."
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
    ]) );
    SetExits( ([
    "west" : ROOMS+"7,2,-3.c",
    "east" : ROOMS+"9,2,-3.c",
    ]) );
    AddExit("up", ROOMS+"8,2,-2.c", (: CheckWander :));
}

int CheckWander()
{
    object who = this_player();
    if(userp(who)) return 1;
    if(who->GetProperty("cave_wander")) return 1;
    return 0;
}
