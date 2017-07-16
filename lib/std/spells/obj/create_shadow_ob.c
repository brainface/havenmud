#include <lib.h>
inherit LIB_ITEM;
void destme();
int life = 480;
static void create() {
item::create();
        SetKeyName("globe");
        SetId( ({ "globe", "globe of shadows", 
              }) );
  SetProperty("magic", "This is a globe of shadows.");
        SetAdjectives("globe");
        SetShort("a globe of shadows");
        SetLong("A gleaming black globe of shadows shimmers "
                "in the air before you.  It provides some small "
                "darkness.");
        SetClass(3);
        SetMass(0);
        SetValue(0);
        SetRadiantLight(-30);
        set_heart_beat(1);
}

void heart_beat() {
   life--;
   if(!life) { destme(); }
}

void destme() {
        if (environment(this_object())) {
                message("system","A small globe of magical darkness "
                        "flickers out.",environment(this_object()) );
                }
       eventDestruct();
}
