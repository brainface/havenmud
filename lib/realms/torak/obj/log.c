#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_SIT;

static void create() {
  item::create();
  SetKeyName("log");
  SetId( ({ "log" }) );
  SetAdjectives( ({ "swamp", "dark", "murky" }) );
  SetShort("a swamp log" );
  SetLong( "A dark, murky swamp log.  Perfect for Sitting.");
  SetMass(120);
  SetMaterial( ({ "wood", "natural" }) );
  SetPreventGet("No.");
  SetMaxSitters(3);
}
