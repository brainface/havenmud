#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("thri-kreen");
  SetRace("thri-kreen");
  SetGender(random(2) ? "male" : "female");
  SetLevel(50 + random(20));
  SetShort("a thri-kreen");
}