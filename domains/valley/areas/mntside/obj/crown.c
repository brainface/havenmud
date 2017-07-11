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
    SetKeyName("stone crown");                                              
    SetId( ({ "crown","helmet" }) );                                       
    SetAdjectives( ({ "stone" }) );                                        
    SetShort("a stone crown");                                             
    SetLong("The crown is a thick ring of stone which will, when worn "+
      "cover most of your head. This crown is very weighty as is "+
      "appropriate to the head of a head of state.");     
    SetMass(70);                                                          
    SetSize(SIZE_SMALL);
    SetValue(20);                                                         
    SetDamagePoints(450);                                                 
   	SetArmourClass(ARMOUR_NATURAL);
    // SetProtection(PIERCE,6);                                              
    // SetProtection(SLASH,8);                                               
    // SetProtection(COLD,2);                                                
    // SetProtection(BLUNT,6);                                               
    // SetProtection(HEAT,2);                                                
    // SetProtection(ACID,4);                                                
    SetArmourType(A_HELMET);                                              
    SetVendorType(VT_TREASURE | VT_ARMOUR);                               
    SetWear("The crown weighs heavily upon your head.");    
    SetMaterial("natural"); 
    SetWarmth(0);
    SetRepairDifficulty(7);                                               
    SetRepairSkills( ([                                                   
			"natural working" : 10,                                   
			"armour smithing" : 5,                                 
      ]) );                                                    
}                                                                       
