/*    /realms/haun/areas/mines/obj/shirt3.c
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
    SetKeyName("vest");
    SetId( ({ "vest" }) );
    SetAdjectives( ({ "new", "cotton", "thin", "ragged" }) );
    SetShort("a ragged vest");
    SetLong("This thick ragged vest is used to help keep a body warm.  It is"
      " made out of a thick cotton material, which seems to be very durable.");
    SetVendorType(VT_CLOTHING);
    SetMass(35);
    SetSize(SIZE_SMALL);
    SetValue(5);
    SetArmourClass(ARMOUR_CLOTH);
    SetMaterials( ({"textile"}) );
    SetWarmth(20);
    SetRepairSkills( ([
    	"armour smithing"  :  1, 
    	"textile  working"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetDamagePoints(35);
    // SetProtection(COLD, 1);   
    // SetProtection(HEAT, 1);  
    SetArmourType(A_SHIRT);
}
