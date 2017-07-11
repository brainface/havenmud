

/*    /realms/haun/areas/mines/obj/torch.c
 *    created on 12/20/98
 *    by Haun
 */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_BURN;

static void create() {
    ::create();
    SetKeyName("torch");
    SetId( ({ "torch" }) );
    SetAdjectives( ({ "old", "wooden" }) );
    SetShort("an old, wooden torch");
    SetLong("An old, wooden torch with a bit of cloth wrapped around "
      "one end and dipped into a flamable substance.  This appears to have"
      " been well used and worn.");
    SetFlickerString("flickers slightly");
    SetMaxFuel(1000);
    SetValue(20);
    SetMaterials( ({ "wood" }) );
    SetRadiantLight(30);
    SetHeat(20);
    SetMass(10);
    SetDamagePoints(400);
    SetVendorType(VT_LIGHT);
    SetDamageType(BLUNT);
    SetWeaponType("blunt");

}
