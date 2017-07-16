#include <lib.h>
inherit LIB_FISH;

static void create() {
  fish::create();
  SetKeyName("trout");
  SetId( ({"trout"}) );
  SetAdjectives( ({"trout","speckled"}) );
  SetFood("/domains/averath/virtual/island/obj/meal");
  SetShort("a speckled trout");
  SetLong("A long filled out, gray speckled trout.");
  SetMass(15);
  }
