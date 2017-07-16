
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
    "Faint heat radiates from the north wall of the cave, warming "
    "this area slightly. From here the twisting walls of the cavern "
    "wend their way to the east and southwest, highlighted by ripples "
    "covering all walls, curving their way in the same direction. These "
    "lines appear to have been created by the constant shaping action "
    "of the ocean water which made these caves and now is collected "
    "in several of the large pockmarks which cover the ground. Moderate "
    "light shines down from a layer of dark blue lichen which covers "
    "the ceiling."
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
    NPC+"oceanid.c" : 1,
    ]) );
    SetExits( ([
    "east" : ROOMS+"9,4,-4.c",
    "southwest" : ROOMS+"7,3,-4.c",
    ]) );
    AddExit("up", ROOMS+"8,4,-3.c", (: CheckWander :));
}

int CheckWander()
{
    object ob = this_player();
    if(userp(ob)) return 1;
    if(ob->GetProperty("cave_wander")) return 1;
    return 0;
}
