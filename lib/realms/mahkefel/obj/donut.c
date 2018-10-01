#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("donut");
  SetShort("a plastic donut");
  SetId( ({ "donut" }) );
  SetAdjectives( ({ "plastic" }) );
  SetLong("Made of plastic and artlessly painted to look like an frosted donut, this kitschy thing can't even be eaten.");
  SetMass(100);
  SetValue(10);
}

