// illusory lantern, part of illusion summons
//
//


#include <lib.h>
inherit LIB_ITEM;
int Life;
void destme();
static void create() {
item::create();
  SetKeyName("lantern");
  SetProperty("magic", "This is a functional figment of someone's imagination.");
  SetId( ({ "lantern", "illusion" }) );
  SetAdjectives("illusory");
  SetShort("an illusory lantern");
  SetLong("A weightless lantern of translucent wrought iron shines with a "
    "ghostly light.");
  SetClass(0);
  SetMaterial( ({ "metal" }) );
  SetMass(0);
  SetValue(0);
  SetRadiantLight(30);
  set_heart_beat(1);
  Life = 480;
}

void heart_beat() {
  Life--;
  if (!Life) destme();
  }

void destme() {
  if (environment(this_object())) {
    message("system","An illusory lantern fades into memory.",
    environment(this_object()) );
  }
  eventDestruct();
}

