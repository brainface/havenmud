#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("shrubbery");
  SetId( ({ "cardboard", "shrubbery" }) );
  SetAdjectives( ({ "cutout", "child", "child's", "drawing", "of" }) );
  SetShort("a cardboard cutout of a child's drawing of shrubbery" );
  SetLong( "This cheap, flimsy thing was not made by a prodigy. "
    "It is soaked in .. something that smells like dog urine.");
  SetMaterial( ({ "wood" }) );
}
