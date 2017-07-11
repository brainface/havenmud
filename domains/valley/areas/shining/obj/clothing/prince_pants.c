
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "textile" }) ); 

        SetKeyName("green silk pants");
        SetShort("a silk pair of green pants");
        SetId( ({ "pants"}) );
        SetAdjectives( ({ "silk", "pair", "of", "green" }) );
        SetArmourType(A_PANTS);
        SetDamagePoints(1000);
        SetWarmth(20);
        SetValue(0);
        SetSize(SIZE_VERY_SMALL);
        SetLong("The green pants are made of silk. They have markings on them "
                "that resemble those seen around the forest. They are rather "
                "plain but will keep one warm.");
}




