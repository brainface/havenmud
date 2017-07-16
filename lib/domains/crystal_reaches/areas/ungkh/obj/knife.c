//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "hunting" }) );
  SetShort("a hunting knife");
  SetLong("This sharp knife is reliable enough to use both "
          "in combat and for utilitarian purposes. The haft "
          "is a bit of greying wood stained with sweat and "
          "blood.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(550);
  SetClass(6);
  SetMass(100);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetValue(1200);
  SetMaterial( ({"metal","wood",}) );
  SetRepairDifficulty(10);
}
