#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../camp.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetRepairDifficulty(8);
  SetRepairSkills( ([
     "metal working" : 1,
     "weapon smithing" : 1,
    ]) );
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetShort("a fairly dull sword");
  SetAdjectives( ({ "dull" }) );
  SetLong("This is a fairly old, beaten sword.  Its remaining life "
         "cannot be much.  It will probably fall apart shortly.");
  SetDamagePoints(300);
  SetClass(10);
  SetMass(125);
  SetValue(0);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetId( ({"sword"}) );
  SetAdjectives( ({"dull", "fairly"}) );
 }
