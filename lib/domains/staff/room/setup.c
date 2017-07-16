/*  The new birth room.  Does much nicer, cleaner stuff.
 */
#include <lib.h>
#include <damage_types.h>
#include <daemons.h>
#include <rooms.h>
#include <std.h>

inherit LIB_ROOM;
void eventStartPlayer(object);

static void create() {
  room::create();
  SetShort("someplace in the ethereal plane");
  SetObviousExits("out");
  SetExits( ([ 
    "out" : ROOM_START,
    ]) );
  SetLong("This is a nether place in the ethereal plane.");
  SetClimate("indoors");
  }

void init() {
  ::init();
  if (!immortalp(this_player())) { eventStartPlayer(this_player()); }
  }

void eventStartPlayer(object who) {
  string race = who->GetRace();
  string town = who->GetTown();

  this_player()->eventMove(SETUP_D->GetStartRoom(town));
}
