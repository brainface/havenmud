#include <lib.h>
#include <climb.h>
#include "../area.h"
inherit LIB_DUMMY;
inherit LIB_CLIMB;

static void create() {
  dummy::create();
  SetId("chimney");
  SetShort("a wall");
  SetLong("This chimney is lined with soot, but looks like you could climb it.");
  SetClimb(AREA_ROOM + "floor2", CLIMB_UP);
  SetClimb(AREA_ROOM + "cabin", CLIMB_DOWN);
 }
