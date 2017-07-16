#include <lib.h>
inherit LIB_ITEM;

void BlahDie();
int blah = 230;

static void create() {
   item::create();
   SetKeyName("lantern");
   SetShort("an old lantern");
   SetId( ({ "lamp","lantern","light" }) );
   SetAdjectives( ({ "old","red","rusty" }) );
   SetLong("The red lantern is old and rusty.");
   SetClass(2);
   SetMass(10);
   SetValue(3);
   SetRadiantLight(15);
   set_heart_beat(2);
}

void heart_beat() {
   blah--;
   if(!blah) {
      BlahDie();
   }
   return;
}

void BlahDie() {
   if(environment(this_object())) {
      send_messages(({ "" }), "The lantern dies.",
                    environment(this_object()));
   }
   eventDestruct();
}
