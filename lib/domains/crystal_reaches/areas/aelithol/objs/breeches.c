#include <lib.h>
#include <armour_class.h>     
#include <armour_types.h>    
#include <damage_types.h>    
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;          
    static void create() {
    armour::create();         
    SetKeyName("dirty breeches");
    SetId( ({ "breeches", "dirty breeches", "a pair of dirty breeches" }) );
    SetAdjectives( ({ "dirty", "black", "soiled", "damp" }) );
    SetShort("a pair of dirty breeches");
    SetLong("These thick canvas breeches have turned black from their "
      "many years of use.  They are covered mainly with soil and "
      "dust, but it is all aggravated by the material being "
      "damp.");
    SetVendorType(VT_CLOTHING);
    SetArmourType(A_PANTS);
    SetArmourClass(ARMOUR_CLOTH);
    SetMass(80);
    SetValue(10);
    SetDamagePoints(200);
    SetSize(SIZE_MEDIUM);
    SetMaterial("textile");
    SetWarmth(10);
    SetRepairSkills( (["textile working"  :  1,
    ]) );
    SetRepairDifficulty(1);
}
