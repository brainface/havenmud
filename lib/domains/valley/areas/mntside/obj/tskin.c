/* Created by Aramuk 1998 */                                                                    
#include <lib.h>                                                    
#include <armour_types.h>                                           
#include <armour_class.h>
#include <damage_types.h>                                           
#include <vendor_types.h>                                                                                                             
#include <size.h>
inherit LIB_ARMOUR;                                                 

static void create() {                                              
    armour::create();                                               
    SetKeyName("armour");                                           
    SetId( ({ "armour", "skin", "hide" }) );              
    SetAdjectives( ({ "bear","grizzly bear","tanned" }) );                             
    SetShort("a tanned bear skin");                                 
    SetLong("A grizzly bear skin which has been tanned and worked into "+
      "an effective piece of body armour.");            
    SetVendorType(VT_ARMOUR);                                       
    SetMass(200);                                                   
    SetSize(SIZE_SMALL);
    SetValue(250);                                                  
   SetArmourClass(ARMOUR_LEATHER);
    SetDamagePoints(700);                                           
    // SetProtection(BLUNT, 8);                                       
    // SetProtection(SLASH, 10);                                       
    // SetProtection(PIERCE, 6);                                      
    // SetProtection(HEAT, 2);                                         
    // SetProtection(COLD, 6);                                         
    // SetProtection(WATER, 1);                                        
    // SetProtection(ACID, 1);                                         
    SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );     
    SetArmourType(A_ARMOUR);                                        
    SetMaterial( ({ "leather" }) );            
    SetWarmth(15);
    SetRepairDifficulty(6);                    
    SetRepairSkills( ([                        
			"leather working" : 10, 
			"armour smithing" : 7, 
      ]) );  
}                         



/* Approved by Duuktsaryth on Mon Jan 26 12:13:53 1998. */
