#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("pack mule");
  SetRace("horse", "mule");
  SetGender("female");
  SetShort("a lowly pack mule");
  SetId( ({ "mule" }) );
  SetAdjectives( ({ "lowly", "pack" }) );
  SetLong(
    "This creature is a lowly pack mule. It is mainly known for carrying around large objects."
  );
  SetClass("animal");
  SetStat("strength", 100, 1);
  SetLevel(1);
}
