#include <lib.h>
inherit LIB_SCROLL;

static void create() {
  ::create();
  SetKeyName("black-bound book");
  SetShort("a black-bound book");
  SetId( ({ "book" }) );
  SetAdjectives( ({ "black", "bound" }) );
  SetLong(
    "This black-bound book is cold to the touch. Reading it would seem by itself to be an evil act."
    );
  SetSpell("chill aura");
  SetMass(20);
  SetValue(250);
}