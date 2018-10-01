#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
        ::create(); 
        SetArmourClass(ARMOUR_CLOTH); 
        SetMaterials( ({ "textile" }) ); 

        SetKeyName("nice pants");
        SetShort("a nice pair of pants");
        SetId( ({ "pants" }) );
        SetAdjectives( ({ "nice", "pair", "of" }) );
        SetArmourType(A_PANTS);
        SetDamagePoints(500);
        SetWarmth(15);
        SetValue(35);
        SetSize(SIZE_MEDIUM);
        SetLong("This long black pair of pants are comfortably made with "
                "a soft lining that is slightly padded along the back of the "
                "theighs for staying in a seated position for long periods of "
                "time in relative comfortability.");
}
