#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-1,-1,-1);
  SetLong("The almost pitch black tunnel narrows suddenly, as it makes a "
          "sudden twisting turn towards the north. The river of sewage is "
          "shallow enough to easily walk through. Clumps of wet, moldy refuse "
          "line the sides of the tunnel, obviously left by some previous "
          "travellers. Scratches run across the floor and walls of the tunnel "
          "leading north.");
  RemoveExit("west");
  RemoveExit("south");
}
