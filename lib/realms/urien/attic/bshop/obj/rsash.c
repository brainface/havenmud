#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("sash");
  SetId(( {"sash"} ));
  SetAdjectives( ({"furry", "brown"}) );    
  SetShort("a furry brown sash");
  SetLong(
    "This sash is just an animal pelt sewn to itself to "
    "form a loop. It is designed to rest on the wearer's "
    "shoulder and hang loosely across the waist.");  
  SetMass(10);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(5);
  SetRepairDifficulty(10);    
  SetValue(75);
  SetDamagePoints(350);  
  SetArmourType(A_SHIRT);    
  SetRepairSkills( ([
     "natural working" : 10,
     "armour smithing" : 10,
     ]) );
}
