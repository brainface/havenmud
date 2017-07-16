#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../rook.h"
inherit LIB_ITEM;

static void create() {
  item::create();

  SetClass(22);
  SetDamagePoints(1500);
  SetValue(100);
  SetMass(350);
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(22);
  SetMaterial( ({ "natural" }) );
  SetRepairSkills( ([
    "natural working" : 15,
    "weapon smithing" : 10,
  ]) );
    SetKeyName("hammer");
    SetShort("a stone hammer");
    SetAdjectives( ({"stone"}) );
    SetId( ({"hammer","weapon"}) );
    SetLong("This hammer is a standard war hammer.  "
      "There appears to be nothing special about it "
      "other than it is made of stone.");
    SetWeaponType("blunt");
    SetDamageType(BLUNT);

}
  
  
