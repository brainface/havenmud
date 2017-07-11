#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cuisse");
  SetId(( {"cuisse"} ));
  SetShort("a chainmail cuisse");
  SetAdjectives( ({"", "chainmail"}) );  
  SetLong(
    "This sturdy cuisse is crafted of small black chain links. The cuisse "
    "covers most of the legs, leaving very little exposed to danger when "
    "combined with other pieces. It is lined with fine black linen, "
    "providing comfort to the wearer as well as superiour protection."    
  );   
  SetMass(400);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_SMALL);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(5000);
  SetDamagePoints(4000);
  SetArmourType(A_PANTS);  
  SetWear("The black chainmail cuisse feels very comfortable.");
}