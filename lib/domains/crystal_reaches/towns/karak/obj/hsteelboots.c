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
  SetShort("a pair of heavy steel boots");
  SetAdjectives( ({"steel", "pair of"}) );
  SetLong(
    "These sturdy boots are crafted of tough steel. A small carving on the "
    "left boot has a small carving of an anvil, signifying that this piece of "
    "armour was crafted by Kelan, perhaps the finest smith in the Southern "
    "Coast region. The boots entirely cover the wearer's feet, leaving "
    "little exposed to danger when combined with similar pieces. They "
    "are lined with fine silk, providing comfort to the wearer as well as "
    "superiour protection."
  );   
  SetProperty("multiples", 1);
  SetMass(200);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_LARGE);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(3000);
  SetDamagePoints(25000);
  SetArmourType(A_BOOT);  
  SetWear("The steel boots feel very comfortable.");
}
