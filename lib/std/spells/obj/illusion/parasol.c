// illusory parasol (dark lantern), part of illusion summons
//
//


#include <lib.h>
inherit LIB_ITEM;
int Life;
void destme();
static void create() {
item::create();
  SetKeyName("parasol");
  SetProperty("magic", "This is a functional figment of someone's imagination.");
  SetId( ({ "parasol", "illusion" }) );
  SetAdjectives("illusory");
  SetShort("an illusory parasol");
  SetLong("A flimsy parasol of formed of phantasmal filament. Though "
    "immaterial, it does at least cast a shadow in spite of the sun.");  
  SetClass(0);
  SetMaterial( ({ "textile" }) );
  SetMass(0);
  SetValue(0);
  SetRadiantLight(-30);
  set_heart_beat(1);
  Life = 480;
}

void heart_beat() {
  Life--;
  if (!Life) destme();
  }

void destme() {
  if (environment(this_object())) {
    message("system","An illusory parasol fades into memory.",
    environment(this_object()) );
  }
  eventDestruct();
}

