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
  SetShort("Zalbar's test lab");
  SetLong(
    "This is Zalbar's test lab. Room with no exits."
  );
  SetExits( ([
  ]) );
}
