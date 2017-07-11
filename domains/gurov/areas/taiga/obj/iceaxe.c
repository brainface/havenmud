//Illura@Haven
//Sept 2009
//iceaxe
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../taiga.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ice axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "ice" }) );
  SetShort("an ice axe");
  SetLong(
    "This battleaxe of ice has been magically forged to never melt "
    "even in the hottest climes. The hilt of blue metal is etched "
    "with swirling, illegible symbols."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetClass(30);
  SetValue(500);
  SetMass(80);
  SetWeaponType("hack");
  SetMaterial( ({"metal", "natural"}) );
  SetRepairSkills( ([
     "metal working" : 50,
     "natural working" : 50,
  ]) );
  SetRepairDifficulty(50);
  SetDamageType(BLUNT|COLD);
}
