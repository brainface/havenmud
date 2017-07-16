// Vaux@Haven (June 30, 2004)
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create(){
  item::create();
  SetKeyName("cestus");
  SetId( ({ "cestus" }) );
  SetAdjectives( ({ "metal" }) );
  SetShort("a cestus");
  SetLong(
    "This eye-catching weapon has sharp metal blades "
    "protruding from the knuckles of a thick, leather glove. "
    "Wearing this increases the effectiveness "
    "of a punch by mildly gouging your opponent."
  );
  SetClass(9);
  SetDamagePoints(1175);
  SetValue(350);
  SetWeaponType("melee");
  SetDamageType(BLUNT|PIERCE);
  SetMass(50);
  SetMaterial( ({"leather"}) );
  SetVendorType(VT_WEAPON);
}
