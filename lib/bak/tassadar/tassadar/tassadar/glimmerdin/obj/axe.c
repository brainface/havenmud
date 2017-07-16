#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() 
{
item::create();
  SetKeyName("axe");
  SetId( ({ "sharp axe","axe" }) );
  SetShort("a sharp axe");
  SetLong("The sharp blade of the axe tops a three foot staff.");
  SetMass(150); 
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(14);
  SetVendorType(VT_WEAPON);
  
}

