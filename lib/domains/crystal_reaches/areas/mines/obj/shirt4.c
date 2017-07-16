/*    /realms/haun/areas/mines/obj/shirt4.c
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
    SetAdjectives( ({ "leather", "thick", "dirty" }) );
    SetShort("a dirty leather shirt");
    SetLong("This shirt is made out of thick leather.  It seems to be used to"
      " keep individuals warm in cold enviroments.");
    SetVendorType(VT_ARMOUR);
    SetMass(35);
    SetArmourClass(ARMOUR_LEATHER);
    SetSize(SIZE_SMALL);
    SetValue(15);

    SetMaterials( ({"leather"}) );
    SetWarmth(30);
    SetRepairSkills( ([
    	"armour smithing"  :  1, 
    	"leather working"  :  1,
    	]) );
    SetRepairDifficulty(1);
    SetDamagePoints(35);
    // SetProtection(COLD, 1);   
    // SetProtection(HEAT, 1);  
    SetArmourType(A_SHIRT);
}
