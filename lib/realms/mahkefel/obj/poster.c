#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("poster");
  SetShort("a poster of a kitten");
  SetId(({ "poster" }));
  SetAdjectives( ({ "kitten" }) );
  SetLong(
    "A rather anachronistic vibrantly colored poster of a kitten hanging from a "
    "tree branch is tacked to the wall. Some boldly lettered words line the bottom "
    "of the poster."
  );
  SetPreventGet("The poster doesn't seem to want to go anywhere with you.");
  SetRead("default",
    "Hang in there!"
  );
}

