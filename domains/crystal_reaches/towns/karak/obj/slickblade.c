#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
  SetKeyName("shimmering sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "shimmering" }) );
  SetShort("a shimmering sword");
  SetLong(
    "This sword is quite long and made of a strange looking metal which "
    "appears to have been twisted from once piece and stretched to form "
    "a blade, cross-guard, handle and pommel. The blade is very hard and "
    "shiny, causing light to refract strangely. It seems as if the dark "
    "gem in the sword's pommel is absorbing light and refracting it out "
    "through the finely-honed blade."
  );
  SetWeaponType("slash");
  SetDamageType(MAGIC|SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2500);
  SetClass(18);
  SetMass(250);
  SetValue(1500);
  SetMaterial( ({ 
  	"metal"
  }) );
  SetRepairDifficulty(60);
  SetProperty(
    "magic", "The metal of the blade is exuding power at an enormous rate."
  );
}
