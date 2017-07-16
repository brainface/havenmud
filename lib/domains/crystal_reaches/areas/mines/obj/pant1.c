/*    /realms/haun/areas/mines/obj/pant1.c
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
    SetAdjectives( ({ "worn", "cotton", "brown" }) );
    SetShort("a pair of brown pants");
    SetLong("These brown pants are made from thin cotton.  They appear to be"
      " in good shape, except in the areas around the knees, in which they are slightly"
      " worn.");
    SetVendorType(VT_ARMOUR);
    SetMaterials( ({"textile"}) );
    SetArmourClass(ARMOUR_CLOTH);
    SetWarmth(10);
    SetRepairSkills( ([
    	"armour smithing"  :  1,
      "textile  working"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetMass(50);
    SetSize(SIZE_SMALL);
    SetValue(15);
    SetDamagePoints(140);
    // SetProtection(HEAT, 1); 
    // SetProtection(COLD, 1);  
    SetArmourType(A_PANTS);
}


/* Approved by Duuktsaryth on Sun Dec 20 01:45:11 1998. */
