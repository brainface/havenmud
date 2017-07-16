/*    /realms/haun/areas/mines/obj/shirt1.c
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
    SetKeyName("shirt");
    SetId( ({ "shirt" }) );
    SetAdjectives( ({ "old", "cotton", "thin", "tattered" }) );
    SetShort("a tattered shirt");
    SetLong("This thin, tattered shirt is made from lightweight cotton."
      " There are small holes that have worn through it.");
    SetVendorType(VT_CLOTHING);
    SetMass(25);
  SetArmourClass(ARMOUR_CLOTH);
    SetSize(SIZE_SMALL);
    SetMaterials( ({"textile"}) );
    SetWarmth(10);
    SetRepairSkills( ([
    	"armour smithing"  :  1, 
    	"textile  working"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetValue(5);
    SetDamagePoints(35);
    // SetProtection(COLD, 1);   
    // SetProtection(HEAT, 1);  
    SetArmourType(A_SHIRT);
}


/* Approved by Duuktsaryth on Sun Dec 20 01:46:30 1998. */
