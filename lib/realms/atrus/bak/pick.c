#include <lib.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("pick");
    SetId("pick", "axe");
    SetAdjectives( ({ "wooden" }) );
    SetShort("a pick");
    SetLong("A plain, wooden handled pick. You probably can mine " 
            "things with it.");
    SetMass(87);
    SetProperty("mining item", 1);
    SetValue(50);
}
