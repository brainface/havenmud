
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
    "The north wall seems to eminate a faint amount of heat, which "
    "causes the air in this section of the cave to be a little warmer "
    "than that to the southwest. The heat from the wall seems to continue "
    "to the east. Various pools of water are scattered across the floor "
    "of cave, tucked into the ripples and pockmarks of the floor. Similar "
    "imperfections cover the grey stone of the walls and ceiling. Also "
    "on the ceiling are small dots of green lichen which glow faintly, "
    "lighting the area."
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
    NPC+"crab2.c" : 1,
    ]) );
    SetExits( ([
    "east" : ROOMS+"9,4,-3.c",
    "southwest" : ROOMS+"7,3,-3.c",
    ]) );
    AddExit("down", ROOMS+"8,4,-4.c", (: CheckWander :));
}

int CheckWander()
{
    object ob = this_player();
    if(userp(ob)) return 1;
    if(ob->GetProperty("cave_wander")) return 1;
    return 0;
}
