// Mahkefel 2010
// guess what this does.
#include <lib.h>

inherit LIB_ITEM;
inherit LIB_SIT;

static void create() {
  ::create();
  SetShort("an odd wicker chair");
  SetKeyName("chair");
  SetId( ({"chair" }) );
  SetAdjectives( ({ "wicker", "odd" }) );
  SetLong(
    "A strange chair sits here, it's base an upside down bowl with four legs "
    "rising to meet a circular seat. Arms flow upware to each side, and the "
    "back fans out, an intricate peacock design woven into the wicker. The "
    "wicker strands seem to be wood, but a strange alchemical smell wafts "
    "from them."
  );
  SetMass(100);
  SetMaterial("natural");
  SetMaxSitters(1);
  SetDamagePoints(250);

}

