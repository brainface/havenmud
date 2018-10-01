#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetId(( {"shirt"} ));
  SetShort("a fashionable black shirt");
  SetLong(
    "This finely made shirt is completely black. It is very fashionable "
    "in the city of Dalnairn, where appearances are extremely important. "
    "It looks warm, but not very durable."    
  	);  
  SetAdjectives( ({"fashionable", "black"}) );  
  
  SetMass(15);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetMaterial("textile");
  SetWarmth(8);
  SetRepairDifficulty(10);    
  SetValue(100);
  SetDamagePoints(300);  
  SetArmourType(A_SHIRT);    
}