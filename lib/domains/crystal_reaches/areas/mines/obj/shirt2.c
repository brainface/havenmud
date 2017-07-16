/*    /realms/haun/areas/mines/obj/shirt2.c
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
    SetAdjectives( ({ "new", "cotton", "thin", "crisp" }) );
    SetShort("a crisp shirt");
    SetLong(
    	"This thin, newly made shirt is made from lightweight cotton."
      " It seems to be made from strong material, which will give it "
      "years of use."
      );
    SetVendorType(VT_CLOTHING);
    SetMass(30);
    SetSize(SIZE_SMALL);
    SetArmourClass(ARMOUR_CLOTH);
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
