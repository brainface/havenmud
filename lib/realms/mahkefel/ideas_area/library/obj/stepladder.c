/* Mahkefel 11/2010
 * puzzlepiece for the arcanith library
 * stepladder allows you to 'climb' up the up exits in rooms
 *
 * prooobaaably needs code to keep it from working outside of library area
 */

#include <lib.h>
#include <climb.h>
#include <domains.h>
#include "../arc_library.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

int climb_up = 0;

static void create() {
  ::create();
  SetKeyName("stepladder");
  SetShort("an ancient stepladder");
  SetId( ({ "ladder","stepladder" }) );
  SetAdjectives( ({ "ancient", "step" }) );
  SetLong(
    "This old steel stepladder has weathered the ages "
    "remarkably. Whatever paint it once had is long gone, "
    "but the steps still look solid, and you could still use "
    "it to climb to inaccessible places."
  );
  SetClimb(ARC_LIBRARY_ROOM "room/second10", CLIMB_UP);
}

mixed CanClimb(object who, int type) {
  object room;

  room = environment();
  if (who == room) {
    return "It's hard to climb a ladder while holding it above the ground.";
  }
  if (climb_up == 0) {
    return "But there's nothing to climb to!";
  }
  return ::CanClimb(who,type);
}

// stepladder set's its up/down climbs to the room's up/downs
int eventMove(mixed dest) {
  climb_up = 0;

  if (dest->GetExit("up")) {
    SetClimb(dest->GetExit("up"), CLIMB_UP);
    climb_up = 1;
  }

  return item::eventMove(dest);
}

    
    


