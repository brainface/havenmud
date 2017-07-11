#include <lib.h>
#include "../keryth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetDomain("FrostMarches");
  SetTown("Keryth");
  SetShort("along a road in Keryth");
  SetLong("Snow has piled up against the building to the south, and, as "
          "there is no entrance into it from here, none has been cleared "
          "away.  Another building has a well cleared path leading up to "
          "it; it is the tavern of Keryth.  The snow has been cleared out "
          "along the road to the southeast, northeast, and west.  There is "
          "a small building to the east which seems like some kind of "
          "laboratory.");
  SetItems( ([
    ({ "windblow snow", "snow", "scintillating crystals",
       "scintillating crystal", "crystal", "crystals", "white drifts",
       "white drift", "drift", "drifts", "frozen water", "water" }) :
       "The scintillating crystals of frozen water are piled high in white "
       "drifts against the buildings; paths have been cleared leading to "
       "the tavern and along the road to the northeast, west, and southeast.",
    ({ "road in keryth", "road", "keryth" }) :
       (: GetLong :),
    ({ "south building", "bank", "building" }) :
       "The building to the south is the bank.  It looks like it might be "
       "enterable from the stretch of road to the southeast.",
    ({ "tavern", "pub", "building" }) :
       "The single story brick building is the tavern of Keryth.  A path "
       "leads up to the entrance, cleared of the windblown snow.",
    ({ "east building", "laboratory", "building" }) :
       "This small but sturdy building seems to get very little use.",
    ({ "well cleared path", "cleared path", "path" }) :
       "The well cleared path leads into the tavern to the east.  Snow has "
       "been piled up along the sides, probably done while the path was "
       "being cleared."
  ]) );
  SetExits( ([
    "northeast" : K_ROOM + "/outskirt",
    "southeast" : K_ROOM + "/road2",
    "west"      : K_ROOM + "/road4",
    "north"     : K_ROOM + "/wharf",
  ]) );
  SetEnters( ([
    "tavern" : K_ROOM + "/tavern",
     "laboratory" : "/domains/frostmarches/areas/lab/room/foyer",
  ]) );
  SetInventory( ([ K_NPC + "/citizen" : random(2)+1 ]) );
  SetListen( ([
    "default" : "Only the sound of footsteps in the snow can be heard."
  ]) );
}
