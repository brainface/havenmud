#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "textile" }) ); 

        SetKeyName("brown shoes");
        SetShort("a brown pair of shoes");
        SetId( ({ "shoes" }) );
        SetAdjectives( ({ "brown", "pair", "of" }) );
        SetArmourType(A_BOOT);
        SetDamagePoints(1000);
        SetProperty("multiples", 1);
        SetWarmth(10);
        SetValue(0);
        SetSize(SIZE_VERY_SMALL);
        SetLong("This brown pair of shoes appears to be valuable only to "
                "the prince. They are made of a cloth material. However, "
                "they do appear to be rather warm.");
}










