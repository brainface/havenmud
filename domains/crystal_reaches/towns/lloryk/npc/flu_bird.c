/* The bird flu carrier
 */
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("chicken");
  SetShort("a small chicken");
  SetRace("bird");
  SetGender("male");
  SetInventory( ([
    STD_GERMS + "bird_flu" : 1,
    ]) );
  SetClass("animal");
  SetLevel(1);
  SetLong("This small chicken looks like it has spent most of his life on the "
          "farm. His feathers are a nice dusty white and he is quiet fat.");
  SetId( ({ "chicken" }) );
  SetAdjectives( ({ "small", "fat" }) );
}
