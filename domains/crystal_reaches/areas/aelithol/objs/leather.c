#include <lib.h>        
#include <armour_class.h>     
#include <armour_types.h>    
#include <damage_types.h>    
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;          
    static void create() {
    armour::create();         
    SetKeyName("leathers");
    SetId( ({ "leathers", "light leathers", "some light leathers" }) );
    SetAdjectives( ({ "light" }) );
    SetShort("a suit of light leathers");
    SetLong("These leathers were perfectly crafted by a leather working "
      "master.  Unfortunatly, they are of little use, for they are "
      "bad protection in combat.");
    SetVendorType(VT_ARMOUR);
    SetArmourType(A_BODY_ARMOUR);
    SetMass(140);
    SetValue(50);
    SetDamagePoints(300);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_LEATHER);
    SetMaterial( ({"leather"}) );
    SetWarmth(10);
    SetRepairSkills( ([
        "leather working" : 7,
    ]) );
    SetRepairDifficulty(30);
}
