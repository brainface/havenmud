/* A warning sign */
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetShort("a warning sign");
  SetLong("This is a wooden sign listing something.");
  SetRead("default",
    "Be warned dangerous statues and dragons await those who venture into this cave.");
 SetPreventGet("You cannot take that!");
  }
