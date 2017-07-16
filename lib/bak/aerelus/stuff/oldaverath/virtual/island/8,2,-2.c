
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
    "Grey stone forms this cave which appears to have been created "
    "by the wearing action of the ocean water over time. Small craters "
    "are scattered across the ground, some of them containing pools "
    "of ocean water. Salt water drips from green lichen coating the ceiling. "
    "Faint light glows from the lichen, illuminating the cave which "
    "branches off in several directions from this point."
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
    "illuminate the cave. In this area the lichen is soaked with ocean "
    "water which occasionally drips down into the small tidal pools which "
    "are scattered across the ground.",
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
    NPC+"sea_urchin.c" : 1,
    ]) );
    SetExits( ([
    "west" : ROOMS+"7,2,-2.c",
    "south" : ROOMS+"8,1,-2.c",
    ]) );
    AddExit("down", ROOMS+"8,2,-3.c", (: CheckWander :));
}

int CheckWander()
{
    object who = this_player();
    if(userp(who)) return 1;
    if(who->GetProperty("cave_wander")) return 1;
    return 0;
}
