#include <lib.h>
inherit LIB_SCROLL;

static void create() {
  ::create();
  SetKeyName("scroll");
  SetShort("an ancient and tattered scroll");
  SetId( ({ "scroll" }) );
  SetAdjectives( ({ "ancient", "tattered","and" }) );
  SetLong(
    "This scroll, obviously made for a reader of immense girth, is frozen and "
    "preserved by a thick layer of ice, without which it would likely have "
    "crumbled to dust long ago. A single word is visible on the unwound "
    "parchment, straining your eyes near to bleeding as it seems to almost "
    "demand to be deciphered."
    );
  SetSpell("fimbulwinter");
  SetMass(200);
  SetValue(2500);
}

