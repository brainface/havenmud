#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("jar of spiders");
  SetShort("a jar of spiders");
  SetId(({ "jar" }));
  SetAdjectives( ({ "jar" }) );
  SetLong(
    "Holy fucking christ it's a jar of spiders. All times, all sizes, just "
    "crammed right in there. You think one is even a weird transformer. And a "
    "sticker? But most of all oh god real spiders."
  );
}
