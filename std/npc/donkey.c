#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("donkey");
  SetRace("horse", "donkey");
  SetGender("male");
  SetShort("a grey pack donkey");
  SetId( ({ "donkey" }) );
  SetAdjectives( ({ "grey", "pack" }) );
  SetLong(
    "This is a grey male donkey. For years donkey's have been used as pack animals for"
    " various traders."
  );
  SetClass("animal");
  SetStat("strength", 100, 1);
  SetLevel(1);
}
