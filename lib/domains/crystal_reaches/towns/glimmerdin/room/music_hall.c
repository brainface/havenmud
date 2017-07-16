#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Glimmerdin Orchestral Hall");
  SetClimate("indoors");
  SetTown("Glimmerdin");
  SetAmbientLight(30);
  SetProperty("no conjuring", 1);
  SetProperty("no teleport", 1);
  SetExits( ([
    "out" : G_ROOM "gh_west",
    ]) );
  SetLong(
    "High vaulted ceilings make for excellent accoustical design here, "
    "and the Orchestral Hall of Glimmerdian is a wonder of musical "
    "planning.  A large stage rises from the far end of the hall, "
    "where bards or thespians have been know to put on a show. "
    "The hall has enough seating for nearly one thousand dwarves "
    "to fill the hall."
    );
  SetItems( ([
    ({ "ceiling", "ceilings" }) :
        "The ceiling is high and vaulted with small light globes to "
        "provide some soft glow.",
    ({ "globe", "light", "lights", "globes" }) : 
        "The light globes are small and softly glowing.",
    ({ "stage" }) :
        "The stage is a well polished wooden structure large enough "
        "for a full play or large symphony to play.",
    ({ "seats", "seat", "seating" }) :
        "The seats are stone, but polished and almost comfortable "
        "looking.",
    ]) );
  SetItemAdjectives( ([
    "ceiling" : ({ "high", "vaulted", }),
    "globe"   : ({ "small", "light", }),
    "stage"   : ({ "large", }),
    ]) );
  SetSmell( ([
    "default" : "The smell of polished wood from the stage taints the hall.",
    ]) );
  SetListen( ([
    "default" : "Excellent acoustics provide wonderful sound quality here.",
    ]) );
  SetInventory( ([
    G_NPC "karl" : 1,
    ]) );
}