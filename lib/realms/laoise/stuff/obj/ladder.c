/*   portia 5-16-99
    the ladder from level 2 to level 3.
 */

#include <lib.h>
#include <climb.h>
inherit LIB_DUMMY;
inherit LIB_CLIMB;

static void create() {
  dummy::create();
  SetKeyName("ladder");
  SetShort("a large ladder");
  SetId( ({"ladder"}) );
  SetAdjectives( ({"large"}) );
  SetLong("This ladder is very tall and looks very easy to climp up.");
  SetClimb("/domains/havenwood/areas/waterfall/rooms/level3/camp1", CLIMB_UP);
  }
