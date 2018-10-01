#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetTown("Grymxoria");
  SetShort("the Temple of the Dark Goddess");
  SetLong(
    "This is the eastern chapel of the Temple of the Dark "
    "Goddess. There are benches for the worshippers to sit "
    "in thought and contemplate the impurity of the world. "
    "All around, set in the walls, are large stain glass "
    "windows depicting the history of the Nosferatu, lit by "
    "some unknown source."
  );
  SetItems( ([
    ({ "bench", "benches" }) : "Long benches of carved black "
    "marble.",
    ({ "wall", "walls" }) : "Walls of large, roughly carved, "
    "black stone.",
    ({ "windows", "large windows", "stain glass windows", 
    "large stain glass windows." }) : "These windows depict "
    "the history of the Nosferatu. They show the period of "
    "enlightenment, the re-emergence, and the embarkation "
    "of the new crusade of purification."
  ]) );
  SetExits( ([ 
    "west" : G_ROOM + "church2b",
    "south" : G_ROOM + "town_hall3b",
    "down" : G_ROOM + "church2a"
  ]) );
}

