#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();

    SetKeyName("spiked poleaxe");
    SetId( ({ "spiked poleaxe", "poleaxe" }) );
    SetAdjectives( ({ "spiked" }) );
    SetShort("a spiked poleaxe");
    SetLong("This razor sharp poleaxe has a spike protruding from the back "
          "of the blade, and the trademark insignia of Sklaag the Mauler on "
          "the three foot long haft.");
    SetMaterial( ({ "metal", "wood" }) );
    SetRepairSkills( ([
          "weapon smithing" : 15,
          "wood working" : 12,
          "metal working" : 12,
					]) );
    SetRepairDifficulty(40);
    SetVendorType(VT_WEAPON);
    SetDamagePoints(2000);
    SetClass(16);
    SetMass(450);
    SetValue(1200);
    SetHands(2);
    SetWeaponType("hack");
    SetDamageType(SLASH|PIERCE);
}
