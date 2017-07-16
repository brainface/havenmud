#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the barracks");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetExits( ([
    "west" : G_ROOM +"barracks1",
    ]) );
  SetLong(
    "Arrayed along the walls of this room are bunks of various "
    "sizes. All, however, are neatly made to reflect the discipline "
    "that is prevalent in the Grymxoria Guards. Various lockers seem "
    "large enough to hold the personal belongings of the members of "
    "the guard. A barred window looks out east over the Estergrym "
    "mountains, and a fireplace at the back of the barracks warms "
    "the room."
    );
  SetItems( ([
    ({ "fire", "fireplace" }) : 
        "This large stone fireplace has a warm fire burning in it.",
    ({ "bunk", "bunks" }) : "The bunks are beds of various sizes, "
                            "but are all neatly made and arranged.",
    ({ "locker", "lockers" }) : "The lockers are large enough to "
                            "hold personal belongings.",
    "window" : "The window looks out over the Estergrym Mountains.",
    ]) );
  SetItemAdjectives( ([
    "window" : ({ "barred" }),
    ]) );
  SetSmell( ([
    "default" : "The fire gives off faint ash into the air.",
    ]) );
  SetInventory( ([
    G_NPC "gemma" : 1,
    ]) );
}
