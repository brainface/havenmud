#include <lib.h>
inherit LIB_WAGON;

static void create() {
  ::create();
  SetKeyName("caravan");
  SetShort("a colorful caravan");
  SetId( ({ "caravan" }) );
  SetAdjectives( ({ "colorful" }) );
  SetLong(
    "This four wheeled carriage is painted a bright, if garish, green and "
    "white shutters line the single window on each side. The drivers seat in "
    "front has the thinnest of blankets for curshioning, and a door on the "
    "rear allows ingress."
  );
  SetBridgeDescription(
    "It smells faintly of sawdust and paint."
  );
  SetValue(1000000);
  SetMaxSitters(3);
}

