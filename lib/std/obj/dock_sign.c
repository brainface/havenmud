#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetShort("an ominous looking warning sign");
  SetId(({ "sign" }));
  SetAdjectives( ({ "ominous","warning","looking" }) );
  SetLong(
    "This large sign sits atop a wooden pole set into the docks. A yellow lightning "
    "bolt paints the left side of the sign, and large block letter writing could be "
    "read on the right, repeated in several languages."
  );
  SetPreventGet("The sign's not going anywhere the entire dock isn't.");
  SetRead("default",
    "WARNING! Board during storms at your own risk!"
  );
}
