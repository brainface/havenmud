#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("battleaxe"); 
  SetShort("a large battleaxe");
  SetId( ({ "axe", "battleaxe" }) );
  SetHands(2);
  SetAdjectives( ({ "large", "battle" }) );
  SetLong("This oversized axe is thick for hefty overhand hacking "
         "in a huge arc of death and cleaving.");
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(750);
  SetClass(13);
  SetMass(275);
  SetValue(300);
  }
