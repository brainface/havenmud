#include <lib.h>         
#include <armour_class.h>    
#include <armour_types.h>    
#include <damage_types.h> 
#include <vendor_types.h>   
#include <size.h>

    inherit LIB_ARMOUR;          
    static void create() {
    armour::create();         
    SetKeyName("tunic");
    SetId( ({ "tunic", "stained", "a stained tunic" }) );
    SetAdjectives( ({ "stained", "old" }) );
    SetShort("a stained tunic");
    SetLong("This tunic is very old and stained by long hours of use in "
         "the fields.");
    SetVendorType(VT_CLOTHING);
    SetArmourType(A_SHIRT);
    SetArmourClass(ARMOUR_CLOTH);
    SetMass(60);
    SetValue(10);
    SetDamagePoints(150);
    SetSize(SIZE_MEDIUM);
    SetMaterial("textile");
    SetWarmth(5);
    SetRepairSkills( ([
    		"textile working"  :  1,
    		]) );
    SetRepairDifficulty(1);
}
