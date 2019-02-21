// Mahkefel 2010
// guess what this does.
#include <lib.h>

inherit LIB_ITEM;
inherit LIB_SIT;

static void create() {
  ::create();
  SetShort("a strange leather couch");
  SetKeyName("couch");
  SetId( ({"couch" }) );
  SetAdjectives( ({ "leather" }) );
  SetLong(
    "A perhaps overcushiony brown leather couch lies here. It looks rather "
    "comfortable as couches go, but smells a bit off and doesn't seem to be "
    "entirely stationary."
  );
  SetMass(500);
  SetMaxSitters(4);
  SetDamagePoints(250);
  SetMaterial("leather");
}

