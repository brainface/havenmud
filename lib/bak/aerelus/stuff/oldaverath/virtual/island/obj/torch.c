#include <lib.h>
inherit LIB_TORCH;

static void create() {
  torch::create();

  SetKeyName("torch");
  SetId( ({ "torch", "old torch", "wooden torch" }) );
  SetAdjectives( ({"old","wooden"}) );
  SetShort("an old, wooden torch");
  SetLong("An old, wooden torch with a bit of cloth wrapped around "
     "one end and dipped into a flamable substance.");
  SetRadiantLight(30);
  SetMass(50);
  SetValue(6);
  SetBurntValue(5);
  SetClass(10);
  SetFuelRequired(1);
  SetMaxFuel(1000);
  SetFuelAmount(1000);
  SetRefuelable(1);
}
