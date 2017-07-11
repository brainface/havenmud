#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({"large", "polished", "well-polished"}) );
  SetShort("a large sword");
  SetLong("This large well-polished sword looks like a fearsome weapon "
          "in the hands of one skilled to use it. Etched into the "
          "base of the blade is the symbol of the Kylin faith, a "
          "balance with dragon entwined around it. The crossbar of "
          "the hilt is simple and unadorned. The hilt's grip is "
          "wrapped in hard leather strips to prevent the users hand "
          "from slipping during combat.");
  SetMass(200);
  SetValue(1000);
  SetDamagePoints(2000);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(35);
  SetMaterial( ({"metal"}) );
  SetRepairDifficulty(30);
  SetVendorType(VT_WEAPON);
}

