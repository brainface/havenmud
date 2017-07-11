//Illura@Haven
//Sept 2009
//evokerknife
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ice shard");
  SetId( ({ "shard" }) );
  SetAdjectives( ({ "ice" }) );
  SetShort("an ice shard");
  SetLong(
    "This shard of ice has been magically forged to never melt "
    "even in the hottest climes. The hilt of blue metal is etched "
    "with swirling, illegible symbols."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetClass(20);
  SetValue(500);
  SetMass(40);
  SetWeaponType("knife");
  SetMaterial( ({"metal", "natural"}) );
  SetRepairSkills( ([
     "metal working" : 50,
     "natural working" : 50,
  ]) );
  SetRepairDifficulty(50);
  SetDamageType(SLASH|COLD);
}
