#include <lib.h>
inherit LIB_ITEM;

string caster;

static void create() {
  item::create();
  SetKeyName("storm");
  SetId( ({ "storm" }) );
  SetShort("a snow storm");
  SetPreventGet(
    "Looking up into the storm, you catch a "
    "%^BOLD%^snowflake%^RECET%^ on your tongue."
  );
  SetLong("A blizzard of snow flurries from the sky.");
}

void init() {
  if (environment()) {
    environment()->SetClimate("arctic");
  }
}
