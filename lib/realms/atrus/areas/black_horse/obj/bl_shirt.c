/* A shirt for Moe */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "textile" }) ); 
        SetRepairSkills( ([ "textile working" : 25, ]) );
        SetRepairDifficulty(15);
        SetKeyName("cotton shirt");
        SetShort("a black cotton shirt");
        SetId( ({ "shirt" }) );
        SetAdjectives( ({ "black", "cotton" }) );
        SetArmourType(A_SHIRT);
        SetDamagePoints(800);
        SetWarmth(25);
        SetValue(10);
        SetSize(SIZE_MEDIUM);
        SetLong("This shirt is a medium cotton shirt that offers little "
                "real protection. Though, since it is made of cotton, it is "
                "mildly flame retardant. There is a small yellow stain on the "
                "lower half of the front.");
}
