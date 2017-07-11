// Diseased Loaf for thorians
// Thoin@haven

#include <lib.h>
#include <meal_types.h>
#include <vendor_types.h>
#include <std.h>

inherit LIB_MEAL;
void eventDecay();
int life = 1000;

static void create() {
    meal::create();
    SetKeyName("mystic loaf");
    SetId( ({ "loaf", "bread" }) );
    SetAdjectives( ({ "mystic", "warm" }) );
    SetShort("a mystic loaf of warm bread");
    SetLong("This delectable looking loaf was created "
            "magically.  It looks absolutely delicious!");
    SetMass(12);
    SetStrength(50);
    SetValue(0);
    SetMealType(MEAL_FOOD);  
    SetMealMessages("The loaf fills your tummy.",
                    "$N tears into a mystic loaf.");
    set_heart_beat(1);
}   

mixed eventEat(object who) {  
   who->eventPrint("The loaf fills your tummy.");
   environment(who)->eventPrint(who->GetName()+" tears into a mystic loaf.", who);
  switch(random(100)) {
   case 0..25 :  
     STD_GERMS "cold"->eventInfect(who);
   break;
   case 26..50 :
     STD_GERMS "flu"->eventInfect(who);
   break;
   case 51..75 :
     STD_GERMS "wither"->eventInfect(who);
   break;
   case 76..100 :
     STD_GERMS "waste_sick"->eventInfect(who);
   break;
  }
    who->eventPrint("A mystic loaf of warm bread is entirely used up.");
    eventDestruct(); 
     return 1;  
}


void heart_beat() {
   life--;
   if(!life) { eventDecay(); }
}

void eventDecay() {
    if (environment())
  message("food_action",
     "A mystic loaf decays into nothingness.",
      environment() );
    eventDestruct();
  }
