/* pick.c for Abandoned Mine
   Tassadar@Haven
   11SEP04
*/

#include <lib.h>
inherit LIB_ITEM;
static void create() {
    item::create();
    SetKeyName("pick");
    SetId("pick");
    SetAdjectives( ({ "wooden" }) );
    SetShort("a pick");
    SetLong("A plain, wooden handled pick. It looks like a mining " 
            "tool. The metal head is elongated on one end to a "
            "curved spike, while the other end is flattened to "
            "a sharp axe blade.");
    SetMass(87);
    SetMaterial( ({ "wood" }) );
    SetRepairSkills( ([
      "wood working" : 1,
      ]) );
    SetRepairDifficulty(2);
    SetProperty("mining item", 1);
    SetDamagePoints(500);
    SetValue(50);
}
