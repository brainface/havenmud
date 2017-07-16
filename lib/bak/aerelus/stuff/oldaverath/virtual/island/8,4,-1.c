
// Entrance to the Ocean Cave
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
    SetShort("entrance to an Ocean Cave");
    SetLong(
    "The opening in the carn widens gradually as it slopes downward "
    "into the beginning of a cave. All the walls of this fissure are "
    "made of a pockmarked grey stone, which appears to have been worn "
    "and shaped by the continual action over time of the ocean. Small "
    "basins have been worn into the floor, with salt water occupying "
    "several of them. Illumination comes from a green lichen which coats "
    "the ceiling, glowing faintly. From here the cave twists downward, "
    "appearing to grow continually larger, or extends back up to the "
    "surface and the opening in the carn."
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
    SetExits( ([
    "up" : ROOMS+"8,4,0.c",
    "down" : ROOMS+"8,4,-2.c",
    ]) );
}
