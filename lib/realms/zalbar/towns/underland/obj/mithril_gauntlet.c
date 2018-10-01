#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("gauntlet");
  SetId(( {"gauntlet" } ));
  SetShort("a mithril platemail gauntlet");
  SetAdjectives( ({"mithril","platemail"}) );
  SetLong(
    ""    
  );     
  SetMass(60);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_SMALL);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(110);
  SetValue(3500);
  SetDamagePoints(25000);
  SetArmourType(A_GLOVE);  
  SetWear("The gauntlet slides onto your hand easily.");
}
