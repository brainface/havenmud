#include <lib.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("spider beer");
  SetShort("a bottle of spider beer");
  SetId(({ "beer","bottle" }));
  SetAdjectives( ({ "bottle","of","spider" }) );
  SetLong(
    "It's... a bottle of budweiser just crammed full of spiders. It doesn't "
    "even smell like beer. Just spiders. Really fucking clever, huh?"
  );
}

