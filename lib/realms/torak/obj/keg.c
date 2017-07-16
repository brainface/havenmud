#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

int pour(string args);

 static void create() {
  ::create();
  SetKeyName("keg");
  SetId( ({ "keg" }) );
  SetShort("a keg");
  SetLong("This is a keg of beer.. (pour beer). It's "
    "cold to the touch and has a self pumping mechanism "
    "that keeps the beer perfect and flowing at all times!");
  SetMass(1);
}


void init() {
  ::init();
  add_action("pour", "pour");
  }

int pour(string args) {

  if (!args) {
    message("system", "Perhaps you should try to <pour beer> next time.",
    this_player() );
    return 1;
    }

  if (args == "beer") {
    new("realms/torak/obj/kegbeer.c")->eventMove(this_player());
    message("system", "You pour a beer from the keg.", this_player() );
    return 1;
    }

return 0;
}
