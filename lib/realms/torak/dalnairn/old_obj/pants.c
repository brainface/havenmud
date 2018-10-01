#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetId(( {"pants"} ));
  SetShort("a pair of black pants");
  SetLong(
    "These pants are extremely fashionable in the city of Dalnairn. "
    "They are entirely black, made from a reasonably durable material. "
    "They should keep the wearer warm while offering minimum protection."    
  );  
  SetAdjectives( ({"pair of", "black"}) );  
  
  SetMass(15);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetMaterial("textile");
  SetWarmth(8);
  SetRepairDifficulty(10);    
  SetValue(100);
  SetDamagePoints(300);  
  SetArmourType(A_PANTS);    
}