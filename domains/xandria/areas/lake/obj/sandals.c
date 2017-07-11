//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetKeyName("sandals");
        SetShort("a pair of sandals");
        SetId( ({ "shoes", "sandals" }) );
        SetAdjectives( ({ "pair", "of" }) );
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "natural" }) ); 
        SetArmourType(A_BOOT);
        SetDamagePoints(800);
        SetProperty("multiples", 1);
        SetWarmth(10);
        SetValue(2);
        SetSize(SIZE_MEDIUM);
        SetLong("These sandals keep the wearer's toes from being stubbed "
                "and lace up comfortably to the calf. ");
}
