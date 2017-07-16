
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
      "Deep ripples create faint scallops along all sides of the grey "
      "walls which form this cave. From here the cave trails away to the "
      "east and west. A faint green light eminates from above, lighting "
      "the cave. The light appears to be coming from many small spots of "
      "light green lichen which are scattered across the ceiling. Small "
      "pools of ocean water exist in parts of the floor where the water "
      "has worn away the rock, forming pockmarks."
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
      NPC+"crab.c" : 3,
    ]) );
    SetExits( ([
      "west" : ROOMS+"6,2,-3.c",
      "east" : ROOMS+"8,2,-3.c",
    ]) );
}
