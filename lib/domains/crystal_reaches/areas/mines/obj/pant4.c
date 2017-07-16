/*    /realms/haun/areas/mines/obj/pant4.c
 *    created on 12/20/98
 *    by Haun
*/
#include <lib.h> 
#include <armour_types.h>  
#include <armour_class.h>
#include <damage_types.h>    
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;          
static void create() {
    armour::create();         
    SetKeyName("pants");
    SetId( ({ "pants" }) );
    SetAdjectives( ({ "dirty", "leather" }) );
    SetShort("a pair of dirty leather pants");
    SetLong("These leather pants are very dirty.  It has made out of a very"
      " durible leather that will hold up to even the toughest activities.");
    SetVendorType(VT_ARMOUR);
    SetMass(50);
    SetArmourClass(ARMOUR_LEATHER);
    SetSize(SIZE_SMALL);
    SetMaterials( ({"leather"}) );
    SetWarmth(20);
    SetRepairSkills( ([
    	"armour smithing"  :  1, 
    	"textile  working"  :  1,
    	]) );
    SetRepairDifficulty(1);
    SetValue(25);
    SetDamagePoints(140);
    // SetProtection(HEAT, 1); 
    // SetProtection(COLD, 1);  
    SetArmourType(A_PANTS);
}
