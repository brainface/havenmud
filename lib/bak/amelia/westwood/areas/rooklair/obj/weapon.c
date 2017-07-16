#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../rook.h"
inherit LIB_ITEM;

int type = random(3);

static void create() {
item::create();
  if (type == 0) {
    SetKeyName("sword");
    SetShort("a stone sword");
    SetAdjectives( ({"stone"}) );
    SetId( ({"sword","weapon"}) );
    SetLong("This sword is a standard long sword.  "
      "There appears to be nothing special about it "
      "other than it is made of stone.");
    SetWeaponType("sword");
    SetDamageType(SLASH);
  }
  else if(type == 1) {
    SetKeyName("hammer");
    SetShort("a stone hammer");
    SetAdjectives( ({"stone"}) );
    SetId( ({"hammer","weapon"}) );
    SetLong("This hammer is a standard war hammer.  "
      "There appears to be nothing special about it "
      "other than it is made of stone.");
    SetWeaponType("hammer");
    SetDamageType(BLUNT);
  }
  else if(type == 2) {
    SetKeyName("spear");
    SetShort("a stone spear");
    SetAdjectives( ({"stone"}) );
    SetId( ({"spear","weapon"}) );
    SetLong("This spear is a standard long spear.  "
      "There appears to be nothing special about it "
      "other than it is made of stone.");
    SetWeaponType("spear");
    SetDamageType(PIERCE);
  }
  SetClass(16);
  SetDamagePoints(1500);
  SetValue(100);
  SetMass(350);
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 15,
    "weapon smithing" : 10,
  ]) );
}
