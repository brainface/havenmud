//Illura@Haven, Aug 2011
//Embroidery Floss for Crafting
#include <lib.h>
#include <std.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("embroidery floss");
  SetShort("a hank of embroidery floss");
  SetId( ({"hank", "floss"}) );
  SetAdjectives( ({ "embroidery" }) );
  SetLong("The pigments used to dye this fancy embroidery thread are vibrant. The thread seems of very good quality and knot-free.");
  SetMass(1);
  SetValue(3);
}

