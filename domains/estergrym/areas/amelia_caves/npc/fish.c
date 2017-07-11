// Amelia@Haven

#include <lib.h>
inherit LIB_FISH;
#include "../cave.h"
 
static void create() {
  fish::create();
  SetProperty("grymxcavenoleave",1);
  SetKeyName("cave fish");
  SetFood( C_OBJ + "meal.c");
  SetShort("a cave fish");
  SetLong(
    "This is a blind cave fish."
  );
  SetMass(20);
  SetId( ({ "fish" }) );
  SetAdjectives( ({ "cave","blind" }) );
}
