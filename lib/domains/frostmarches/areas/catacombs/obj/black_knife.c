#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("black bladed knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "black", "black bladed" }) );
  SetShort("a black bladed knife");
  SetLong("This knife is about eight inches in length"
          " and has one extremely sharp side. The blade"
          " has been painted black to aid in its concealment."
  );
  SetClass(18);
  SetDamagePoints(1000);
  SetValue(900);
  SetWeaponType("knife");
  SetDamageType(PIERCE | MAGIC);
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
