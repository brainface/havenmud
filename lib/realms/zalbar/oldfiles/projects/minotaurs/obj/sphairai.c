// Zalbar Aug 08


#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;
inherit LIB_WEAPON;

static void create(){
  ::create();
  SetKeyName("sphairai");
  SetId( ({ "sphairai","glove" }) );
  SetAdjectives( ({"battle"}) );
  SetShort("a sphairai");
  SetLong(
    "This battle glove is made of leather strips wrapped around the "
    "wearer's wrist and knuckles. There four iron spikes on the "
    "knuckles of the glove to help cause additional damage."); 
  SetClass(20);
  SetDamagePoints(1200);
  SetValue(500);
  SetWeaponType("melee");
  SetDamageType(BLUNT|PIERCE);
  SetMass(50);
  SetMaterial( ({"leather"}) );
  SetVendorType(VT_WEAPON);
  SetSize(SIZE_LARGE);
  SetArmourType(A_WEAPON);
  SetArmourClass(ARMOUR_LEATHER);
}
