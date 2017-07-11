/*
 * Zeratul@Haven
 * For skull of darkness
 * 11/10/2001
 */

#include <lib.h>
inherit LIB_ITEM;

void destme();
int life = 240;

static void create() {
  item::create();
  SetKeyName("skull");
  SetId( ({"skull","skull of darkness"}) );
  SetProperty("magic","This skull is creating a negative effect on the light in the "
     "room, making it darker. ");
  SetAdjectives("summoned");
  SetShort("a skull of darkness");
  SetLong(
      "This skull is nearly pitch black, as light around it is turned into darkness. "
  );
  SetClass(3);
  SetMass(0);
  SetValue(0);
  SetRadiantLight(-10);
  set_heart_beat(1);
}

void heart_beat() {
  life--;
  if(!life) { destme(); }
}

void destme() {
     if (environment(this_object())) {
     message("system","The skull of darkness implodes on itself.",
     environment(this_object()) );
    }
    eventDestruct();
}
