// A large, heavy portable trunk. The object of this trunk
// is to nail a really heavy object to a character who has 
// strength maxxed, and it has to be too heavy to him.

#include <lib.h>
#include "../castle.h"

inherit LIB_STORAGE;

static void create() {
  ::create();
  SetKeyName("trunk");
  SetId( ({ "trunk" }) );
  SetAdjectives( ({ "wooden", "large"}) );
  SetShort("a black wooden trunk");
  SetLong("The craftsmanship of this rectangular container has "
          "been displayed quite well. The planar surfaces along "
          "the sides are dried black wood which have been fastened "
          "together along metal straps. Bolts along the straps of "
          "this container secure the lid from opening. It is a "
          "large trunk, with no security latch at all. The top is "
          "rectangular in shape, flat. It could seat two humans "
          "comfortably or used as a table easily. The wood it was "
          "made with is thick and also could withstand decent abuse. "
          "It appears quite heavy.");
  SetMass(7000); 
  SetCanClose(1);
  SetMaxCarry(4200); //Large trunk, semi lower capacity.
}