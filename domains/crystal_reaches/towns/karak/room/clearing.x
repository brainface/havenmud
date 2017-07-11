// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an open area");
  SetLong(
    "This is an area of flatten-down dirt, formed in to the shape of a "
    "rough circle. It appears to have been caused by countless feet tramping "
    "across the ground and smoothing it down. Streaks of dark color and gouges "
    "from heels and other body parts suggest its use as a training area for "
    "the residents of Karak. To the southwest is a quiet area among the "
    "trees which appears to be the town cemetery."
  );
  SetItems( ([
    ({ "dirt", "ground", "area", "circle" }) : "The impact of countless "
    "feet moving across this area has flattened it in to a rough circle "
    "of dirt.",
    ({ "streaks", "gouges", "color", "patches", "substance", "blood" }) : 
    "Patches and streaks of a substance which is dark against the dirt "
    "are scattered across the area. When combined with the visible "
    "evidence of physical conflict seen here, it appears likely to be "
    "blood from previous combatants.",
    ({ "groups", "buildings" }) : "A group of buildings to the east "
    "appear used as a marketplace. A second group to the south is "
    "comprised of larger buildings and appears to be the seat of power.",
  ]) );
  SetItemAdjectives( ([
    "dirt" : ({ "flat", "flattened", "down", "open", "dirt", "training" }),
    "streaks" : ({ "dark", "heel", "body", "part", "colored", "scattered" }),
    "groups" : ({ "building", "east", "eastern", "south", "southern" }),
  ]) );
  SetSmell( ([
    "default" : "The air is nearly free of dirt here.",
  ]) );
  SetListen( ([
    "default" : "The eerie silence of the calm before battle hangs over the clearing.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "leader_rogue" : 1,
    KARAK_NPC + "citizen2" : 1,
  ]) );
  SetExits( ([
    "east"      : KARAK_ROOM + "rd3",
    "southwest" : KARAK_ROOM + "cemetery",
  ]) );
}
