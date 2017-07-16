#include <lib.h>
inherit LIB_ITEM;
 
void BlahDie();
int life = 2000+random(50);
 
static void create() {
   item::create();
   SetKeyName("blackrock");
   SetShort("a chunk of blackrock");
   SetId( ({ "blackrock","chunk","rock" }) );
   SetAdjectives( ({ "dark","black" }) );
   SetLong("The blackrock is completely dark and black, absorbing the "
           "light around it.");
   SetClass(1);
   SetMass(20);
   SetValue(0);
   SetRadiantLight(-15);
   set_heart_beat(1);
   SetProperty("magic","The blackrock pulls light inside, making it "
               "darker.");
}
 
void heart_beat() {
   life--;
   if(!life) { BlahDie(); }
}
 
void BlahDie() {
   if(environment(this_object())) {
      send_messages( ({ "" }), "The blackrock dissolves with the energy "
                        "of the light it has captured.",
                        environment(this_object()));
   }
   eventDestruct();
}
