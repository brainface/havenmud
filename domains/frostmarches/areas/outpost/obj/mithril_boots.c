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
  SetShort("a pair of mithril boots");
  SetAdjectives( ({"silver"}) );
  SetLong(
    "These sturdy boots are crafted of mithril. "
    "The boots entirely cover the wearer's feet, leaving "
    "little exposed to danger when combined with similar pieces. They "
    "are lined with soft fur, providing some added comfort."
  );   
  SetProperty("multiples", 1);
  SetMass(200);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(2800);
  SetArmourType(A_BOOT);  
}