#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "textile" }) ); 

        SetKeyName("high heels");
        SetShort("a shiny pair of high heels");
        SetId( ({ "heels" }) );
        SetAdjectives( ({ "shiny", "pair", "of", "high", }) );
        SetArmourType(A_BOOT);
        SetDamagePoints(5000);
        SetProperty("multiples", 1);
        SetWarmth(10);
        SetValue(1);
        SetSize(SIZE_MEDIUM);
        SetLong("This shiny and beautiful pair of heels seem to have never "
                "been worn until now. They are black in color with a glittering buckle "
                "just above the open toe.");
}
