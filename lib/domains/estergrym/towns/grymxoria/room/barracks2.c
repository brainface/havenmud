#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a training room");
  SetLong(
    "This is a training room in the Grymxoria city barracks. "
    "In the center of the room there is a circle of bare floor "
    "for sparring. Small stains on the floor look like they "
    "might be blood. Along the walls are racks of different weapons. "
    "The smooth stone of the walls is marred by several nicks and "
    "scratches."
  );
  SetItems( ([
    ({ "floor" }) : "A sparring circle of bare stone is in the "
    "center of the room. There are brownish red splotches on "
    "it that look like they might be blood.",
    ({ "stain", "stains", "splotch", "splotches" }) : "The "
    "splotches seem to be dried blood. Training in Grymxoria is "
    "real.",
    ({ "rack", "racks" }) : "Racks of weapons are ranged along "
    "the wall. There are many different weapons including spears, "
    "swords, axes, knives, bows, and others.",
  ]) );
  SetItemAdjectives( ([
    "floor" : ({ "bare", "circle", "of", }),
    "stain" : ({ "brownish", "red", "small", "blood" }),
    "rack"  : ({ "weapon", "weapons", }),
  ]) );
  SetInventory( ([
    G_NPC "cyra" : 1,
  ]) );
  SetSmell( ([
    "default" : "The stench of stale sweat is heavy here.",
  ]) );
  SetExits( ([
    "south" : G_ROOM "barracks1",
    ]) );
}
