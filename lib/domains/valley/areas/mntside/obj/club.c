/* Aramuuk 1998 */
#include <lib.h>                                              
#include <vendor_types.h>                                     
#include <damage_types.h>                                     
inherit LIB_ITEM;                                             
static void create() {                                        
    item::create();                                       
    SetShort("a studded club");                    
    SetLong("Jagged pieces of metal and stone "             
      "protrude from the head of this "             
      "crude but effective club");                  
    SetId( ({"club", "studded club"}) ); 
    SetClass(11);
    SetDamagePoints(550);
    SetValue(150);                                        
    SetWeaponType("blunt");                                
    SetDamageType(BLUNT|PIERCE);                                 
    SetKeyName("club");                                   
    SetMass(250);                                         
    SetVendorType(VT_WEAPON);                             
    SetAdjectives( ({ "studded" }) );            
    SetMaterial( ({ "natural" }) );            
    SetRepairDifficulty(4);                    
    SetRepairSkills( ([                        
			"natural working" : 4, 
			"weapon smithing" : 3, 
      ]) );  
}                                                             
