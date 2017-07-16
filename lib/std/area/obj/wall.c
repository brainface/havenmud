#include <lib.h>
#include <climb.h>
inherit LIB_DUMMY;
inherit LIB_CLIMB;

static void create() {
  dummy::create();
  SetKeyName("wall");
  SetId( ({ "wall" }) );
  SetShort("a wall");
  SetLong("This is a climbable wall.");
  SetClimb("/std/room/roof",CLIMB_UP);
 }
