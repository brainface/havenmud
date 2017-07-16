/* Aramuuk 1988 */   
#include <lib.h>                                          
#include <vendor_types.h>                                 
#include <damage_types.h>                                 
inherit LIB_ITEM;                                         

static void create() {                                    
    item::create();                                   
    SetShort("a stone axe");                   
    SetLong("This three and a half foot long weapon "+
      "is topped by a wide blade hewn from an "+
      "unknown type of black stone. The edge gleams "+
      "in the light and appears quite deadly.");                  
    SetId( ({"axe","stone axe","stone"}) ); 
    SetClass(14);                                     
    SetDamagePoints(700);
    SetValue(350);                                    
    SetWeaponType("hack");                            
    SetDamageType(SLASH);                             
    SetKeyName("axe");                         
    SetMass(350);                                     
    SetVendorType(VT_WEAPON);                         
    SetAdjectives( ({ "stone" }) );                   
    SetHands(2);                                      
    SetMaterial( ({ "natural" }) );            
    SetRepairDifficulty(5);                    
    SetRepairSkills( ([                        
			"stone working" : 8, 
			"weapon smithing" : 3, 
      ]) );  
}
