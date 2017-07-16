#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-1,1,-1);
  SetLong("The walls of the tunnel curve in as they go up, forming a sort "
     "of arch in the center. The dark stones the wall is made of are "
     "covered in a wet slime from the refuse that passes through. The "
     "ground in the center of the tunnel, hardly visible, carries a "
     "small stream of waste from the tunnels toward a grate on the floor. "
     "Small wooden torches that hang from the wall barely manage to keep "
     "this area lit.");
  SetItems( ([
     ({"grate"}) : "The small stream of muck and waste flow through the "
       "loosened grate. A small person could fit through the grate to "
       "the darkness below.",
     ({"wall","walls"}) : "These dark stone walls are wet and slimy "
       "from the passage of refuse through the tunnels.",
     ({"ground","floor","waste","refuse","stream"}) : "Small amounts of "
       "waste flow through the tunnel here, adding to a large river of "
       "refuse to the east. Some of the waste flows into a small grate.",
     ({"torch","torches"}) : "The occasional small wooden torch hangs "
       "from the walls to give a dim view of the passages ahead.",
     ]) );
  SetInventory( ([AVERATH_NPC + "hbeggar" : 1 ]) );
  SetEnters( ([
     "grate" : AVERATH_UNDERGROUND "-1,1,-2",
     ]) );
  RemoveExit("west");
  RemoveExit("south");
  RemoveExit("north");
}
