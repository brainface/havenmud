/* handy haversack of holding.
 * 2500 capacity.             
 *                            
 */                           
#include <lib.h>              
#include <armour_class.h>     
inherit LIB_WORN_STORAGE;
#include <armour_types.h>     
#include <size.h>             
#include <vendor_types.h>     

static void create() 
  {                  
  ::create();        
  SetKeyName("haversack");
  SetId( ({ "haversack", "sack" }) );
  SetAdjectives( ({ "large","rune-marked","rune","marked" }) );
  SetShort("a large rune-marked haversack");
  SetLong("This haversack is a small backpack with a single strap"
    " meant to be worn over the shoulder. Oddly, strange blue runes"
    " crawl up the shoulder strap and spiral around the body."      
    " Looking into the interior gives a sense of profound depth."   
  );                                                                
  SetCanClose(1);                                                   
  SetClosed(1);                                                     
  SetDamagePoints(2000);                                            
  SetMass(100);                                                     
  SetMaterial( ({ "textile" }) );                                   
  SetMaxCarry(2500); // largest other one i saw was 1000            
  SetProperty("magic",                                              
    "This haversack has been enchanted to provide greater volume."  
  );                                                                
  SetRepairSkills( ([ "textile" : 1,]) );                           
  SetRepairDifficulty(80);
  SetArmourType(A_VEST);  
  SetValue(1500);
  SetVendorType(VT_CLOTHING);
  SetWarmth(10);
}
