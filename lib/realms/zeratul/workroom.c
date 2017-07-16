/*
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 *  Minor editing by Laoise@Haven
 *  "This is my bitch" by Zeratul@Haven
 */
#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("%^MAGENTA%^Zeratul's Workroom%^RESET%^");
  SetLong(
    "This area is void of any visible boundaries. It exists in the void between space and time."
  );
  SetSmell( ([
    "default" : "This place is empty of all scents.",
  ]) );
  SetListen( ([
    "default" : "The void is quiet and empty.",
  ]) );
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "east" : "/realms/zeratul/areas/tutorial/room/begin1",
  ]) );
}
