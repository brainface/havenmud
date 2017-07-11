//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "textile" }) ); 
        SetKeyName("sandals");
        SetShort("a pair of old sandals");
        SetId( ({ "sandals" }) );
        SetAdjectives( ({ "old", "pair", "of" }) );
        SetArmourType(A_BOOT);
        SetDamagePoints(1000);
        SetProperty("multiples", 1);
        SetWarmth(10);
        SetValue(10);
        SetSize(SIZE_MEDIUM);
        SetLong("This old pair of sandals is made from the finest straw "
                "available, woven into a comfortable sort of footware "
                "that is only slightly better than going barefoot.");
}

