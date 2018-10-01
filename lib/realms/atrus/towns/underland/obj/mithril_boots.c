#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId(( {"boots" } ));
  SetShort("a pair of mirthil platemail boots");
  SetAdjectives( ({"mithril", "platemail", "pair of"}) );
  SetLong(
    "These shining mithril boots are of the finest quality, "
    "the encasement of the foot is complete while the inter-"
    "locking plates allow for free movement."
  );   
  SetProperty("multiples", 1);
  SetMass(140);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(40);
  SetValue(3000);
  SetDamagePoints(25000);
  SetArmourType(A_BOOT);  
  SetWear("The mithril boots feel light and nimble.");
}
