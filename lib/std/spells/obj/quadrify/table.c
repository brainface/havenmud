// Mahkefel 2010
// guess what this does.
#include <lib.h>

inherit LIB_ITEM;
inherit LIB_SIT;

static void create() {
  ::create();
  SetShort("a long wooden table");
  SetKeyName("table");
  SetId( ({"table" }) );
  SetAdjectives( ({ "long", "wooden" }) );
  SetLong(
    "A long wooden table hewn from a dark wood. The grain warps oddly across "
    "the surface, as if it was subject to a great strain, but it appears "
    "quite sturdy. The four legs curve outwards slightly at each corner."
  );
  SetMass(500);
  SetMaxSitters(4);
  SetDamagePoints(250);
  SetMaterial("wood");

}

