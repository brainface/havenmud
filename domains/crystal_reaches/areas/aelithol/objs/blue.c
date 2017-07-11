#include <lib.h>
#include <armour_class.h>          
#include <armour_types.h>    
#include <damage_types.h>    
#include <vendor_types.h>
#include <size.h>

    inherit LIB_ARMOUR;          
    static void create() {
    armour::create();         
    SetKeyName("blue pants");
    SetId( ({ "pants", "blue pants", "a pair of blue pants" }) );
    SetAdjectives( ({ "blue", "small", "thin", "gray", "brown" }) );
    SetShort("a pair of blue pants");
    SetLong("These small pants have become thin as paper over "
      "time.  At one time they were probably blue but now they "
      "are somewhere between gray and brown in hue.");
    SetVendorType(VT_CLOTHING);
    SetArmourType(A_PANTS);
    SetArmourClass(ARMOUR_CLOTH);
    SetMass(50);
    SetValue(10);
    SetDamagePoints(100); 
    SetSize(SIZE_SMALL);
    SetMaterial("textile");
    SetWarmth(5);
    SetRepairSkills( (["textile working"  :  1, 
    ]) );
    SetRepairDifficulty(1);
}
