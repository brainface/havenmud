/* Aramuuk 1998 */
#include <lib.h>                                      
#include <damage_types.h>                             
#include <armour_class.h>
#include <armour_types.h>                             
#include <vendor_types.h>                             
#include <size.h>

inherit LIB_ARMOUR;                                                                                      
static void create()                                  
{                                                     
    armour::create();                                   
    SetKeyName("fur boots");                        
    SetId(( { "boots","boot" } ));                      
    SetAdjectives( ({ "pair of","fur" }) );         
    SetShort("a pair of fur boots");                
    SetLong("These boots are made from the skin of some kind of thick "+
      "furred beast. They look as if they'd keep your feet quite warm.");           
    SetMass(35);                                        
    SetSize(SIZE_SMALL);
    SetValue(25);                                       
    SetDamagePoints(400);                               
    SetArmourClass(ARMOUR_LEATHER);
    // SetProtection(PIERCE,4);                            
    // SetProtection(SLASH,3);                             
    // SetProtection(COLD,7);                              
    // SetProtection(BLUNT,2);                             
    // SetProtection(HEAT,2);                              
    // SetProtection(ACID,4);                              

    SetArmourType(A_BOOT);                              
    SetVendorType(VT_TREASURE | VT_ARMOUR);             
    SetWear("Your feet are warmed nicely as you pull on the boots.");
    SetProperty("multiples",1);                         
    SetMaterial( ({ "leather" }) );                     
    SetWarmth(10);
    SetRepairDifficulty(5);                             
    SetRepairSkills( ([                                 
			"armour smithing" : 2,          
			"leather working" : 5,          
      ]) );                                
}         


/* Approved by Duuktsaryth on Mon Jan 26 12:10:42 1998. */
