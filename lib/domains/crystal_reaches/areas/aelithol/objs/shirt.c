#include <lib.h>   
#include <armour_class.h>          
#include <armour_types.h>    
#include <damage_types.h>    
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;          
    static void create() {
    armour::create();         
    SetKeyName("shirt");
    SetId( ({ "shirt", "old shirt", "old shirt" }) );
    SetAdjectives( ({ "old", "cotton", "thin" }) );
    SetShort("an old shirt");
    SetLong("The old shirt is made from cotton.  It is paper "
      "thin.");
    SetVendorType(VT_CLOTHING);
    SetArmourType(A_SHIRT);
    SetArmourClass(ARMOUR_CLOTH);
    SetMass(30);
    SetValue(5);
    SetDamagePoints(40);
    SetSize(SIZE_MEDIUM);
    SetMaterial("textile");
    SetWarmth(5);
    SetRepairSkills( (["textile working"  :  1,
    ]) );
    SetRepairDifficulty(1);
}
