#include <lib.h>
inherit LIB_FISH;

static void create() {
  fish::create();
  SetKeyName("bass");
  SetId( ({"bass"}) );
  SetAdjectives( ({"bass","large"}) );
  SetFood("/domains/averath/virtual/island/obj/meal");
  SetShort("a large bass");
  SetLong("A nice sized bass with large eyes.");
  SetMass(15);
  }
