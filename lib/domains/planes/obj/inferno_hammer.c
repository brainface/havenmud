// Torak@Haven 2013
// For Lord H in the Fire Planes
// make the players bleed for their new mithril pieces
                                                   
#include <lib.h>                                        
#include <vendor_types.h>                               
#include <damage_types.h>                               
inherit LIB_ITEM;                                       

int SetupProc();

static void create() {
  item::create();     
  SetKeyName("hammer");
  SetId( ({ "hammer" }) );      
  SetAdjectives( ({ "inferno", "glowing" }) );
  SetShort("a glowing inferno hammer");          
  SetLong(
    "The hammer's head is an immense piece of rectangular metal "
    "whose edges glow red with heat. The hollow haft is "
    "filled small lead pellets to absorb the impact when "
    "striking an enemy. "                                         
  );     
  SetHands(2);                                             
  SetClass(50);                                            
  SetWeaponType("blunt");                                  
  SetDamageType(BLUNT|HEAT);                                    
  SetVendorType(VT_WEAPON);                                
  SetDamagePoints(9000);                                   
  SetValue(15000);                                          
  SetMass(400);                                            
  SetMaterials( ({ "metal" }) );                         
  SetRepairDifficulty(60);
  SetRadiantLight(5);
  SetProperty("magic",
    "This hammer has been imbued with the power of "
    "inflicting fire damage upon striking an enemy. "
  );
  SetProperty("history",
    "This hammer was crafted by some fell smith of the "
    " plane of fire."
  );                                                     
}                                                                             
