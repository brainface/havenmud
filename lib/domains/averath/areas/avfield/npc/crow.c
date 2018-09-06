// Originally by Ohtar, I think
//
// Mahk 2018--changed race to bird instead of custom
// changed base lib to npc
// fixed some exp bug.
#include <lib.h>
#include "../avb.h"

inherit LIB_NPC;


static void create() {
   npc::create();
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
   SetRace("bird","crow");
   SetGender("female");
   SetClass("animal");
   SetStat("durability",40,3);
   SetLevel(35);
}

void eventDie(object killer) {
   object item;
   item = new(AVB_OBJ + "/feather");
   item->eventMove(this_object());
   npc::eventDie(killer);
}

