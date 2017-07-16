#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(0,-1,-1);
  SetLong("The dark, foreboding tunnel takes a sudden twisting branch "
     "To the east and west. The stones that make up the tunnel's floor are "
     "treacherously wet, making travel difficult at best. Small intermittent "
     "scratch marks, as if from the claws of some great beast, line the "
     "refuse slicked walls.");
  SetItems( ([
     ({"wall","walls","stone","stones"}) : "The dark stone walls "
       "are covered with a thin layer of muck from the passing river of "
       "sewage.",
     ({"marks","scratch marks"}) : "These marks are obviously made by "
       "some large beast, who must be nearby.",
     ({"floor"}) : "The stones that make up the floor are extremely "
       "slippery, and a small stream of black muck runs down the center.",
     ]) );
  SetInventory( ([
    AVERATH_NPC "prat" : 1,
    AVERATH_NPC "trainertom" : 1,
  ]) );
  RemoveExit("south");
}
