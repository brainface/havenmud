
// Ocean Cave
// Laoise
// May 2001

#include <lib.h>
#include <domains.h>
#include <caves.h>

inherit LIB_ROOM;

int PlayersOnly();

static void create() {
    room::create();
    SetAmbientLight(30);
    SetClimate("underground");
    SetShort("inside an Ocean Cave");
    SetLong(
    "A wide pool of water fills the center of the cave, with narrow "
    "walkways of grey stone to either side. The pool is composed of "
    "sea water from the ocean. Large intermittent patches of green "
    "lichen cover the ceiling, glowing faintly and illuminating this "
    "section of the cave. The glow is more faint here than in other "
    "areas because the lichen is saturated with salt water which drips "
    "occasionally down into the pool. "
    );
    SetListen(
    "default", "The ocean gently roars somewhere nearby.",
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
    "southwest" : ROOMS+"7,3,-2.c",
    "southeast" : ROOMS+"9,3,-2.c",
    ]) );
    AddExit("up", ROOMS+"8,4,-1.c", (: PlayersOnly :));
}

int PlayersOnly()
{
    object ob = this_player();
    if(userp(ob)) return 1;
    return 0;
}
