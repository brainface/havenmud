/*    /realms/haun/areas/mines/obj/breeches1.c
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
    SetKeyName("breeches");
    SetId( ({ "pants", "breeches", "a pair of breeches" }) );
    SetAdjectives( ({ "worn", "cotton", "gray" }) );
    SetShort("a pair of gray breeches");
    SetLong("This pair of thick breeches is worn predominantly by miners and"
      " other occupations where conditions could be very cold.  They seem to"
      " be made of a heavy weight material, and have a dull gray color.");
    SetVendorType(VT_CLOTHING);
    SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
    SetWarmth(30);
    SetRepairSkills( ([
    	"textile working"  :  1, 
    	"armor smithing"  :  1,
      ]) );
    SetRepairDifficulty(1);
    SetMass(80);
    SetSize(SIZE_SMALL);
    SetValue(10);
    SetDamagePoints(140);
    // SetProtection(HEAT, 1); 
    // SetProtection(COLD, 1);  
    SetArmourType(A_PANTS);
}
