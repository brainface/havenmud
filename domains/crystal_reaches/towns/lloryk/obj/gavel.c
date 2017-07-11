#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
        SetKeyName("gavel");
  SetMaterial( ({ "wood" }) );
        SetId( ({ "gavel" }) );
        SetAdjectives( ({ "heavy", "wooden" }) );
        SetShort("a heavy wooden gavel");
        SetLong("Beautiful carving decorates the head of the wooden gavel.");
        SetMass(25); 
        SetValue(150);
        SetDamagePoints(2000);
        SetWeaponType("blunt");
        SetDamageType(BLUNT);
        SetClass(7);
        SetVendorType(VT_WEAPON);
        SetMaterial("wood");
        SetRepairDifficulty(20);
}

