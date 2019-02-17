#include <lib.h>
inherit LIB_WAGON;

static void create() {
  ::create();
  SetKeyName("rickety wagon");
  SetShort("a rickety wagon");
  SetId( ({ "wagon" }) );
  SetAdjectives( ({ "rickety" }) );
  SetLong(
    "A pile of lumber sort of sorted into horizontal and vertical and nailed "
    "together with hope and prayers and then dropped on top of an axle, this "
    "rickety wagon will feel every bump in the road and the ratty tarp "
    "stretched over the top looks more like to attract moths than repel rain."
  );
  SetBridgeDescription(
    "It smells oddly of cheese in here."
  );
  SetValue(100000);
  SetMaxSitters(3);
}

