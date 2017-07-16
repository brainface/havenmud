//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("sharp scythe");
  SetId( ({ "scythe" }) );
  SetAdjectives( ({ "sharp" }) );
  SetShort( "a sharp scythe" );
  SetLong("A jagged metal blade tops a huge pole made of finely polished "
    "wood. Symbols burned into the wood seem to evoke an ancient evil. "
    );
  SetMass(230);
    SetValue(1200);
  SetDamagePoints(1200);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(15);
  SetHands(2);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal","natural" }) );
  SetRepairDifficulty(20);
}
