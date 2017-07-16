#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("buzuq");
  SetShort("a stringed buzuq");
  SetId( ({ "buzuq", "bard_instrument" }) );
  SetAdjectives( ({ "stringed" }) );
  SetLong(
    "A buzuq is a thin-necked stringed instrument played similiar to a guitar "
    "or mandolin.  It is primarily seen in the deserts of Yozrath."
    );
  SetDamagePoints(2500);
  SetValue(150);
  SetMass(40);
  SetHands(2);
  SetWeaponType("hack");
  SetClass(4);
  SetMaterials( ({ "wood", "natural" }) );
  SetRepairDifficulty(5);
}

  