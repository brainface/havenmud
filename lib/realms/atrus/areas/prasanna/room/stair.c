#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;
static void create() {
   room::create();
   SetClimate("indoors");
  SetDomain("Valley");
   SetAmbientLight(25);
   SetShort("a crevice deep in the earth");
   SetLong("The cavern ends abruptly, and begins a vertical rise into the "
           "darkness. An ancient stairway is carved directly into the "
           "sandstone and begins a steep ascent straight up. The steps have "
           "begun to erode with time, and look less than inviting.");
   SetItems( ([ 
      ({ "ancient stairway","stairway","steps","step" }) : 
         "These steps are carved directly into the walls of the cavern, and "
         "begin a climb straight up.",
      ({ "cavern", "cave" }) : 
         "The cavern was carved long ago, and the walls have become smooth "
         "with time and erosion. ", 
      ({ "walls","wall" }) :
         "The walls here are smooth and worn down with time.",
      ({ "sandstone" }) :
         "The walls are solid sandstone, and while soft, the sandstone "
         "has endured the wear and tear of many years.",   ]) );
   SetExits( ([ 
      "up" : PR_ROOM "/stair2",
      "south" : PR_ROOM "/cint" 
   ]) );
}

