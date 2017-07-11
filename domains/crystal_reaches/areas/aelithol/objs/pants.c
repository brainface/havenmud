#include <lib.h> 
#include <armour_class.h>            
#include <armour_types.h>    
#include <damage_types.h>    
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;          
    static void create() {
    armour::create();         
    SetKeyName("pants");
    SetId( ({ "pants", "worn pants", "a pair of worn pants" }) );
    SetAdjectives( ({ "worn", "cotton" }) );
     SetShort("a pair of worn pants");
    SetLong("The pants are made of thick cotton.  They are worn from "
      "many years of use.");
    SetVendorType(VT_CLOTHING);
    SetArmourType(A_PANTS);
    SetArmourClass(ARMOUR_CLOTH);
    SetMass(85);
    SetValue(20);
    SetDamagePoints(140);
    SetSize(SIZE_MEDIUM);
    SetMaterial("textile");
    SetWarmth(20);
    SetRepairSkills( (["textile working"  :  1,
    ]) );
    SetRepairDifficulty(1);
}
