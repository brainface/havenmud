/*  This is a basic workroom object that connects
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 *  Minor editing by Laoise@Haven
 */
#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a workroom");
  SetLong(
"This is Lanikai's workroom.  Warm light flows in through the windows and dust hangs heavy in the air. "



"The walls appear to be made of an ancient sandstone and the curtains sway lazily with the warm breeze. "
"A work bench sits near the window strewn with odd tools. "
" A small bed and chest of drawers sits against the left wall.  A kitchen area with a small stone stove and well is to the right. "
  );
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "east" : STD_AREA "room/basic",
  ]) );
}
