/* Aramuuk --1998 */
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
    SetId( ({ "armour", "skin", "hide", "skin armour"}) );                   
    SetAdjectives( ({ "bear","grizzly bear" }) );                            
    SetShort("a grizzly bear skin");                                         
    SetLong("A grizzly bear skin fashioned into a crude but effective "+
      "armour");                                                                    
    SetVendorType(VT_ARMOUR);                                                
    SetMass(250);                                                            
    SetSize(SIZE_SMALL);
    SetValue(200);                                                           
    SetDamagePoints(600);                                                    
    SetArmourClass(ARMOUR_LEATHER);
    // SetProtection(BLUNT, 7);                                                 
    // SetProtection(SLASH, 9);                                                 
    // SetProtection(PIERCE, 6);                                                
    // SetProtection(HEAT, 2);                                                  
    // SetProtection(COLD, 6);                                                  
    // SetProtection(WATER, 1);                                                 
    // SetProtection(ACID, 1);                                                  
    /* fixed typo on 1/29/98 -- aramuuk */
    SetRestrictLimbs( ({"torso", "right arm", "left arm"}) );
    SetArmourType(A_ARMOUR);                                                 
    SetMaterial( ({ "leather" }) );            
    SetWarmth(15);
    SetRepairDifficulty(5);                    
    SetRepairSkills( ([                        
			"leather working" : 8, 
			"armour smithing" : 6, 
      ]) );  
}


/* Approved by Duuktsaryth on Mon Jan 26 12:13:35 1998. */
