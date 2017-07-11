// passenger attacker for the black night                                            
// mahkefel 2011                                                                     

#include <lib.h>                                        
#include <std.h>                                        
#include <damage_types.h>                               
#include <domains.h>                                      
inherit LIB_PIRATE;                                       

static void create() {
  ::create();         
  SetRace("human");   
  SetGender("male");  
  SetClass("sailor"); 
  SetSkill("enchantment", 1,1);
  SetLevel(1);                 
  SetKeyName("wraith");        
  SetId( ({ "wraith" }) );     
  SetShort("a chained wraith");
  SetAdjectives( ({ "chained" }) );
  SetLong("This poor damned soul has been shackled and wrapped with chains. "
    "Misery and torture are apparent on his ghostly face, and worse yet, he "
    "appears willing to share his lot with any he can see.");                
  SetInventory( ([                                                           
    INNERSEA_ENCOUNTERS "undead/ballandchain" : "wield chain"                
  ]) );                                                                      

  SetCombatAction( 15, ({
    "!say Steel cannot cut me!",
    "!say End this! Please!",   
    "!say Kill... me...",       
    "!emote moan",              
  }) );                         
  SetCaptainAggressiveness(10); 
  SetProperty("pirate", "undead");
  SetShipWander(1);               
  SetDie("The wraith collapses with a look of relief, and slowly fades away.");
  SetNoCorpse(1);                                                              
  SetUndead(1);                                                                
  SetUndeadType("wraith");                                                     
  SetResistance(ALL_PHYSICAL, "immune");                                       
  SetResistance(ALL_ELEMENTS|MAGIC,"none");                                    
  SetResistance(POISON|HUNGER|DISEASE,"immune"); // SKELLINGTON                

  SetMinLevel(1);
  SetMaxLevel(280);
  SetCombatStartVerb("disorient");
} 
