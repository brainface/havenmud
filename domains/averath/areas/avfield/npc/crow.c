#include <lib.h>
#include "../avb.h"

inherit LIB_SENTIENT;


static void create() {
   sentient::create();
   SetProperty("averath cave",1);
   SetKeyName("crow");
   SetShort("a black crow");
   SetId( ({ "crow" }) );
   SetAdjectives( ({ "black" }) );
   SetLong("The black crow has long rough black wings on its back. "
           "Each feather is marred and very rough. It has yellow "
           "outlined eyes with small black pointy pupils. Its beak "
           "is pure black and comes to a curling razor sharp tip. "
           "It has two small holes on each side for breathing. The "
           "crow has four large sharpened nails on each of its two "
           "talons. It is rather large and could be very deadly. ");
   SetRace("crow",1);
   SetGender("female");
   SetClass("animal");
   SetLevel(35);
   SetStat("durability",40,3);
   SetStat("charisma",10,1);
   SetStat("intelligence",2,3);
   SetStat("luck",70,1);
   SetStat("agility",70,1);
   SetStat("wisdom",1,5);
   SetStat("strength",25,3);
   SetStat("coordination",70,2);
   AddLimb("torso",0,1,({ }) );
   AddLimb("head","torso",1,({ }) );
   AddLimb("first left wing","torso",3,({ }) );
   AddLimb("first right wing","torso",3,({ }) );
   AddLimb("left talon","torso",3,({ }) );
   AddLimb("right talon","torso",3,({ }) );
}

void eventDie(object killer) {
   object item;
   item = new(AVB_OBJ + "/feather");
   item->eventMove(this_object());
   sentient::eventDie();
}
