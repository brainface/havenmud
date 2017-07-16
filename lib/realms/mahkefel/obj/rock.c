#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rock");
  SetShort("a rock");
  SetId(({ "rock","brain" }));
  SetAdjectives( ({ "rock" }) );
  SetLong(
    "This is a large chunk of quartz that looks like someone has hurriedly "
    "cleaned the dirt off with a wrag. Something is written on one side with "
    "a sharpie, perhaps you could read it?"
  );
  SetRead("default",
    "BRAIN"
  );
}

