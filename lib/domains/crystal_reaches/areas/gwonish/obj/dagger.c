#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() 
{
item::create();
        SetKeyName("dagger");
        SetId( ({ "dagger" }) );
        SetShort("a sharp dagger");
        SetLong("The dagger's pomel is jeweled.");
  SetMaterial( ({"metal"}) );
  SetRepairSkills( ([
                     "metal working" : 1,
                     "weapon smithing" : 1
                 ]) );
  SetRepairDifficulty(9);
  SetMass(20); 
  SetValue(250);
  SetDamagePoints(1500);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetClass(10);
  SetVendorType(VT_WEAPON);
}
