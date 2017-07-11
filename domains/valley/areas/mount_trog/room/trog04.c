/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../trog.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in a foul smelling burrow");
  SetClimate("underground");
  SetExits( ([
    "north" : TROG_ROOM "trog02",
    ]) );
  SetLong(
    "The tunnel opens here to a foul-smelling hatchery. The area is littered "
    "with small piles of (what is hopefully) dirt. Several discarded bones lie "
    "scattered on the floor. Small piles of nesting material are arranged into "
    "what could only be imagined are sleeping mats. The warren leads back "
    "north towards the tunnels."
    );
  SetItems( ([
    ({ "dirt piles", "pile", "piles", "dirt" }) : "These are piles that, looked at closely, appear to be waste.",
    ({ "nesting piles", "pile", "piles", "material", }) : "These piles are arranged into small sleeping areas.",
    ({ "bone", "bones" }) : "The small cracked bones of rats litter the floor.",
    ]) );
  SetItemAdjectives( ([
    "dirt piles" : ({ "dirt", "small", }),
    "nesting piles" : ({ "nesting", "small", }),
    "bone" : ({ "rat", "discarded", "cracked" }),
    ]) );
  SetInventory( ([
    TROG_NPC "trog1" : 3,
    ]) );
  SetSmell( ([
    "default"       : "The nesting area gives new meaning to the term \"foul stench\".",
    "dirt piles"    : "The piles of waste smell oddly like excrement.",
    "nesting piles" : "The nesting piles don't smell much better than the waste piles.",
    ]) );
}