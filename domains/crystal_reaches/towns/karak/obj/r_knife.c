// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "curved" }) );
  SetShort("a curved knife");
  SetLong(
    "Made with a handle of dark bone, this knife is small but appears sharp, "
    "durable and well-balanced. Its lower edge is serrated and its upper edge "
    "is smooth, but both are sharpened and ready to cut."
  );
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetMass(70);
  SetValue(80);
  SetClass(11);
  SetDamagePoints(1000);
  SetMaterial( ({ 
    "metal" 
  }) );
  SetRepairDifficulty(20);
}
