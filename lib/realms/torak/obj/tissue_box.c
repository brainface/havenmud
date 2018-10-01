#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

int pluck(string args);

 static void create() {
  ::create();
  SetKeyName("box");
  SetId( ({ "box" }) );
  SetShort("a tissue box");
  SetLong("This a seemingly simple box of tissues. "
    "It is light as a feather. A tissue sticks out of "
    "the top of the box.  Perhaps if you <pluck tissue> "
    "you could grab one.");
  SetMass(1);
}


void init() {
  ::init();
  add_action("pluck", "pluck");
  }

int pluck(string args) {

  if (!args) {
    message("system", "Perhaps you should try to <pluck tissue> next time.",
    this_player() );
    return 1;
    }

  if (args == "tissue") {
    new("realms/torak/obj/tissue.c")->eventMove(this_player());
    message("system", "You pluck a tissue from the box.", this_player() );
    return 1;
    }

return 0;
}
