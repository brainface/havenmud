// Coded by Zeratul
// 3-17-2000

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetId( ({"knife","double bladed knife"}) );
  SetAdjectives( ({ "double bladed" }) );
  SetShort("a double bladed knife");
  SetLong(
     "This odd-looking knife is indeed a rare weapon. It has a large leather "
     "handle, with a large blade comming out of it. The blade goes for about "
     "2 inches, then splits off into a duel-blade. "
  );
  SetDamagePoints(1000);
  SetValue(350);
  SetMass(100);
  SetClass(30);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH|PIERCE);
  SetWeaponType("knife");
  SetRepairDifficulty(40);
  SetRepairSkills( ([
     "metal working" : 15,
     "weapon smithing" : 15,
  ]) );
  SetMaterial( ({"metal"}) );
  }
