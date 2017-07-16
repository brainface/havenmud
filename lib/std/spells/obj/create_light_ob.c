#include <lib.h>
inherit LIB_ITEM;
int Life;
void destme();
static void create() {
item::create();
  SetKeyName("globe");
  SetProperty("magic", "This is a globe of light.");
  SetId( ({ "globe", "globe of light", 
            "globe of  ight" }) );
  SetAdjectives("globe");
  SetShort("a globe of light");
  SetLong("A shining blue globe of light shimmers "
          "in the air before you.  It provides some small "
          "light.");
  SetClass(3);
  SetMaterial( ({ "natural" }) );
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
                message("system","A small globe of light "
                        "flickers out.",environment(this_object()) );
                }
        eventDestruct();
}
