/* Aramuuk 1998 */                                                           
#include <lib.h>                                                  
#include <damage_types.h>                                         
#include <vendor_types.h>                                         
inherit LIB_ITEM;                                                 
static void create() {                                            
    item::create();                                                 
    SetKeyName("mace");                                             
    SetShort("a large mace");                                       
    SetId( ({ "mace", "large mace" }) );                            
    SetLong("This is a large mace, suitable to crushing skulls."); 
    SetValue(350);                                                    
    SetDamagePoints(650);
    SetClass(16);                                                   
    SetWeaponType("blunt");                                         
    SetDamageType(BLUNT);                                           
    SetVendorType(VT_WEAPON);                                       
    SetAdjectives( ({ "large" }) );                                 
    SetMaterial( ({ "metal" }) );            
    SetRepairDifficulty(4);                    
    SetRepairSkills( ([                        
			"metal working" : 4, 
			"weapon smithing" : 3, 
      ]) );  
}
