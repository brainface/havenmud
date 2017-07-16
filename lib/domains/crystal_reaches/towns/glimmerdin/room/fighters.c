#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a training hall for fighters");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetTown("Glimmerdin");
  SetExits( ([
    "out" : G_ROOM "gh_central",
    ]) );
  SetLong(
    "The training hall for the Glimmerdin Militia is a very clean and "
    "orderly area with clearly defined places for all manner of weapons "
    "and combat practice. Carved deeply into all the walls are pictures "
    "of various dwarven heroes wielding hammers, axes, and even a few "
    "swords killing the hated foes of the dwarves: orcs and goblins. "
    "At the back of the hall sits a large forge which has obviously "
    "been kept busy."
    );
  SetSmell( ([
    "default" : "The stench of sweaty dwarf fills the air.",
    ]) );
  SetItems( ([
    "forge" : "The forge is owned by Jirvin, the Armourer.",
    ]) );
  SetItemAdjectives( ([
    "forge" : ({ "large" }),
    ]) );
  SetInventory( ([
//  STD_NPC "clefter" : 1,
    G_NPC "civak" : 1,
    G_NPC "armourer" : 1,
    G_NPC "fighter_trainer" : 1,
    G_NPC "armour_equipper" : 1,
    G_NPC "tanner" : 1,
    ]) );
  SetProperty("no conjuring", 1);
  SetProperty("no teleport", 1);
  SetProperties( ([
      "metal working" : 1,
      "natural working" : 1,
      "wood working" : 1,
      "leather working" : 1,
      "textile working" : 1,
      "mithril working" : 1,
   ]) );
}
