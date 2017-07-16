#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(0,0,-1);
  SetLong("The wide tunnel suddenly branches off to the north and south, "
     "the huge river of refuse dividing into twin smaller streams. An "
     "occasional torch breaks the monotony of the dank sewage tunnels.");
  SetItems( ([
     ({"river","sludge","refuse","stream"}) : "A large river of waste runs "
       "through the middle of the room and branches off making two "
       "smaller rivers going north and south.",
     ({"torch","torches"}) : "The occasional small wooden torch hangs from "
       "the walls to give a dim view of the passages ahead.",
     ]) );
  RemoveExit("west");
   SetAmbientLight(26);
}
