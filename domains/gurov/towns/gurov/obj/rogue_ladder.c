#include <lib.h>
#include <climb.h>
#include <domains.h>
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
  ::create();
  SetKeyName("ladder");
  SetShort("a thin rope ladder");
  SetId( ({ "ladder" }) );
  SetAdjectives( ({ "thin", "rope" }) );
  SetLong(
    "This thin rope ladder seems to lead up to an escape "
    "hatch to flee the city quickly."
    );
  SetClimb(GUROV_AREAS "newbiepath/room/trail_ns5", CLIMB_UP);
  SetPreventGet("The ladder is firmly secured to the wooden floor.");
}
  
