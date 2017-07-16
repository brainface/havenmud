/*  This is a basic workroom object that connects
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 */
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("%^MAGENTA%^BOLD%^FLASH%^B_BLUE%^SABRIELLE THE ANGEL'S%^RESET%^"
           " (hopefully almost immortal's) %^MAGENTA%^BOLD%^FLASH%^"
           "B_BLUE%^ROOM%^RESET%^...yeah!             ");
  SetLong("This is not your basic workroom.  It's Sabrielle's workroom "
          "and is therefore the best workroom.  Right now it is pretty "
          "empty... but just wait!  Okay!  Geez, hold your horses! "
          "She's been busy CODING, and hasn't had time to think about "
          "trivial little things like her workroom!  Okay?");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetObviousExits("%^MAGENTA%^north,east%^RESET%^");
  SetExits( ([
     "north" : "/domains/heaven/room/olympus",
     "east"  : STD_ROOM + "basic",
      ]) );
  }
