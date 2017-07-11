#include <lib.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetShort("a field of tall grass");
  SetLong(
    "This field of tall grass encompasses the "
    "entire area, save for the path and channel."
  );
  SetId( ({
    "grass"
  }) );
  SetSmell( ([
    "default" : "The field smells fresh and wild.",
  ]) );
  SetAdjectives( ({ "tall" }) );
  SetKeyName( "field" );
  SetId( ({ "field", "grass" }) );
  SetPreventGet(
    "You can't pick up the entire field!"
  );
}
