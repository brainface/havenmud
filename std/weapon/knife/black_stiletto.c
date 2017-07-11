
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("stiletto");
  SetId( ({ "stiletto", "dagger", "knife" }) );
  SetAdjectives( ({ "black-bladed", "black" }) );
  SetShort("a black-bladed stiletto");
  SetLong(
    "This is a short blade, roughly nine inches in length"
    " that has been crafted to be used for piercing rather"
    " than slashing. The blade and handle have been treated"
    " with ash and charcoal to make the entire ensemble as"
    " black as a starless night."
  );
  SetClass(20);
  SetDamagePoints(4000);
  SetValue(1500);
  SetWeaponType("knife");
  SetDamageType(PIERCE);  
  SetMass(75);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
     "metal working" : 8,
     "weapon smithing" : 8,
  ]) );
  SetRepairDifficulty(20);
  SetVendorType(VT_WEAPON);
}
