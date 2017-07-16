// torak 10/27/12
#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("fire");
  SetId( ({ "fire", "pit" }) );
  SetAdjectives( ({ "fire" }) );
  SetShort("a fire pit" );
  SetLong( "A well kept fire burns away at its "
    "swamp wood fuel with a bed of bright red "
    "and white coals at its center.");
  SetMaterial( ({ "wood" }) );
  SetPreventGet("That hurts!");
}
