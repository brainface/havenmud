/* Aramuuk 1998 */
#include <lib.h>                                                    
#include <armour_types.h>                                           
#include <damage_types.h>                                           
#include <armour_class.h>
#include <vendor_types.h>                                                                                                             
#include <size.h>
inherit LIB_ARMOUR;                                                 

static void create() {                                              
    armour::create();                                               
    SetKeyName("armour");                                           
    SetId( ({ "dress", "doeskin" }) );              
    SetAdjectives( ({ "white", "doeskin" }) );                             
    SetShort("a white doeskin dress");                                 
    SetLong("This is a beautiful dress made from the skin of a white "+
      "or albino doe. The skin is extremely soft and looks quite valuable.");            
    SetVendorType(VT_ARMOUR);                                       
    SetMass(100);                                                   
    SetSize(SIZE_SMALL);
   	SetArmourClass(ARMOUR_LEATHER);
    SetValue(1250);                                                  
    SetDamagePoints(200);                                           
    // SetProtection(BLUNT, 2);                                       
    // SetProtection(SLASH, 2);                                       
    // SetProtection(PIERCE, 3);                                      
    // SetProtection(HEAT, 3);                                         
    // SetProtection(COLD, 5);                                         
    // SetProtection(WATER, 2);                                        
    // SetProtection(ACID, 1);                                         
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );     
    SetArmourType(A_ARMOUR);                                        
    SetMaterial( ({ "leather" }) );            
    SetWarmth(20);
    SetRepairDifficulty(5);                    
    SetRepairSkills( ([                        
			"leather working" : 20, 
			"armour smithing" : 5, 
      ]) );                       
}
