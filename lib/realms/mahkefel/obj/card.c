#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("card");
  SetShort("a nondescript playing card.");
  SetId( ({ "card" }) );
  SetAdjectives( ({ "weathered" }) );
  SetLong("A card");
  SetMass(5);
  SetValue(10);
}
