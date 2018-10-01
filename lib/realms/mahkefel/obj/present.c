#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("present");
  SetShort("an unwrapped present");
  SetId(({ "present" }));
  SetAdjectives( ({ "unwrapped" }) );
  SetLong(
    "Someone has already hurriedly unwrapped and torn apart this cardboard "
    "box. There is nothing inside, but the label shows some expensive "
    "gadgetry that you really wanted. The pictures look really cool. The "
    "actors portrayed look really happy to be holding that gadget."
    );
}


