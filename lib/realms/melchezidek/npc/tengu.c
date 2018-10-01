#include <lib.h>
#include <std.h>

inherit LIB_NPC;

static void create() {
  ::create();
  SetId("tengu");
  SetKeyName("large tengu");
  SetShort("a large tengu");
  SetLong("A large ugly tengu is a bird demon.");
  SetGender("male");
  SetRace("bird", "demon");
  SetClass("ninja");
  SetLevel(45);
}

