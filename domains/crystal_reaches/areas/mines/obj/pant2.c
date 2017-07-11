/*    /realms/haun/areas/mines/obj/pant2.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>    
#include <damage_types.h>    
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;          
static void create() {
    armour::create();         
    SetKeyName("pants");
    SetId( ({ "pants" }) );
    SetAdjectives( ({ "new", "cotton", "brown" }) );
    SetShort("a pair of new brown pants");
    SetLong("These brown pants seem to be new, because of the neatness of"
      " them.  They are brown, and appear to be made out of a"
      " heavy material.  These pants appear as if they would"
      " protect one from the cold.");
    SetVendorType(VT_CLOTHING);
    SetMass(40);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_CLOTH);
    SetWarmth(20);
    SetRepairSkills( ([
    	"textile working"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetMaterials( ({"textile"}) );
    
    SetRepairDifficulty(1);
    SetValue(15);
    SetDamagePoints(140);
    // SetProtection(HEAT, 1); 
    // SetProtection(COLD, 1);  
    SetArmourType(A_PANTS);
}
