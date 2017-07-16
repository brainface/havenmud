#include <lib.h>
inherit LIB_ITEM;

int lower(string args);

static void create() {
  ::create();
  SetKeyName("furry thing");
  SetId("thing");
  SetInvis(10);
  SetPreventGet("");
  SetPreventDrop("");
}

void init() {
  ::init();
  add_action("lower","lower");
}

int lower(string args) {
  this_player()->eventPrint("You lower the shield.");
}
