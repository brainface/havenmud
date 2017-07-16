/*    /realms/haun/areas/mines/obj/boot2.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("boots");
    SetShort("a pair of heavy leather boots");
    SetId( ({ "boots" }) );
    SetAdjectives( ({ "heavy", "leather", "pair"}) );
    SetLong("This is a pair of extreamly heavy boots. They are made of the"
      " very strongest and finest leather available.");
    SetMass(5);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_LEATHER);
    SetProperty("multiples", 1);
    SetValue(50);
    SetVendorType(VT_ARMOUR);
    SetMaterials( ({"leather"}) );
    SetWarmth(10);
    SetRepairSkills( ([
    	"armour smithing"  :  1, 
    	"leather working"  :  1,
    	]) );
    SetRepairDifficulty(1);
    SetArmourType(A_BOOT);
    SetDamagePoints(100);
}
