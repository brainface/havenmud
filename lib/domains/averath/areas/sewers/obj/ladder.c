#include <lib.h>
#include <climb.h>
#include <domains.h>
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
  ::create();
  SetKeyName("ladder");
  SetShort("a rusty ladder");
  SetId( ({ "ladder" }) );
  SetAdjectives( ({ "rusty" }) );
  SetLong(
    "This rusty ladder leads up to the grate, leading to the city of "
    "Averath.");    
  SetClimb(AVERATH_TOWNS "averath/room/road3", CLIMB_UP);
  SetMaterial( ({ "metal" }) );
  SetPreventGet("The ladder is securely fastened to the ground.");
}
