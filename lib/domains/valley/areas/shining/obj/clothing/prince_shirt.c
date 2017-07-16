
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "textile" }) ); 

        SetKeyName("silk green shirt");
        SetShort("a silk green shirt");
        SetId( ({ "shirt" }) );
        SetAdjectives( ({ "silk", "green"  }) );
        SetArmourType(A_SHIRT);
        SetDamagePoints(1000);
        SetWarmth(15);
        SetValue(0);
        SetSize(SIZE_VERY_SMALL);
        SetLong("The green shirt is made of silk. It has markings on it "
                "that resemble those seen around the forest. It is rather "
                "plain but will keep one warm.");
}







