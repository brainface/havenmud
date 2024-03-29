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
    "This is your basic workroom. There is not much to see "
    "here, but if you wanted to you could go north "
    "to get to the staff room of the Immortals. To the east are "
    "several rooms which will give you coding examples."
  );
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "east" : STD_AREA "room/basic",
  ]) );
  SetInventory( ([
    "/realms/duuk/stuff/thing" : 1,
    ]) );
}
