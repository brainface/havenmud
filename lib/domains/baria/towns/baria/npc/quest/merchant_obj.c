#include <lib.h>
inherit LIB_ITEM;
int endwander();

static void create() {
  ::create();
  SetKeyName("merchant_quest_obj");
  SetInvis(1);
  SetPreventGet("");
  SetRetainOnDeath(1);
}

void init() {
  ::init();
  add_action("endwander", "endwander");
}

int endwander() { environment()->cmdEndWander(); }
