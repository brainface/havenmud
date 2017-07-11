/*    /realms/haun/areas/mines/obj/boot1.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("boots");
    SetShort("a pair of old work boots");
    SetId( ({ "boots" }) );
    SetAdjectives( ({ "old", "work", "pair"}) );
    SetLong("This is a pair of extremely old boots. They seem to "
      "have been worn down after many days of use. ");
    SetMass(5);
    SetSize(SIZE_SMALL);
    SetProperty("multiples", 1);
    SetMaterials( ({"textile"}) );
    SetWarmth(5);
    SetArmourClass(ARMOUR_CLOTH);
    SetRepairSkills( ([
    	"armour smithing"  :  1, 
    	"textile working"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetValue(10);
    SetVendorType(VT_CLOTHING);
    SetArmourType(A_BOOT);
    SetDamagePoints(30);
}
