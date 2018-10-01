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
    "This is the western chapel of the Temple of the Dark "
    "Goddess. There are benches for worshippers to sit "
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
    "the history of the Nosferatu. Going from their early days "
    "as bloodthirsty hunters, through their exile into the "
    "depths of the earth."
  ]) );
  SetExits( ([ 
    "east" : G_ROOM + "church2b",
    "south" : G_ROOM + "town_hall1b",
    "down" : G_ROOM + "church1a"]) );
  }
