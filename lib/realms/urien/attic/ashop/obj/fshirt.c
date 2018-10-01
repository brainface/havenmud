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
  SetShort("a green long sleeve shirt");
  SetLong(
    "This long-sleeved shirt has a golden cloth lining with "
    "white stitching. This shirt was made to fit a medium sized "
    "torso."    
        );  
  SetAdjectives( ({"long sleeve", "green", "long-sleeve"}) );  
  
  SetMass(15);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(8);
  SetRepairDifficulty(10);    
  SetValue(100);
  SetDamagePoints(300);  
  SetArmourType(A_SHIRT);    
}
