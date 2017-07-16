/*  This is a basic workroom object that connects
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 */
#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Vanyel's workroom");
  SetLong("This workroom is rather sparse, as if its inhabitants "
          "did not really care to bother with decoration. You have "
          "the odd sense that you really should expect better "
          "from whoever lives here.");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
     "north" : DIR_STANDARD_DOMAIN "/staffroom",
      ]) );
  }
