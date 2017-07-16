#include <lib.h>

inherit LIB_ITEM;
inherit LIB_DIG_WITH;

static void create() {
   ::create();
    SetKeyName("shovel");
    SetId("shovel", "spade");
    SetAdjectives( ({ "wooden" }) );
    SetShort("a shovel");
    SetProperty("farming item", 1,);
    SetLong("A plain, wooden shovel.  You probably can dig things with "
            "it.");
    SetMass(100);
    SetValue(50);
}
