// changed by mahkefel october 2010
//   simplified resistances and cleaned up some behavior
//   got tired of knives everywhere. added rusty cutlass
#include <lib.h>                                        
#include <std.h>                                        
#include <damage_types.h>                               
#include <domains.h>                                      
inherit LIB_PIRATE;                                       

static void create() {
  ::create();         
  SetRace("human");   
  SetGender("male");  
  SetClass("rogue");  
  SetClass("sailor"); 
  SetLevel(125);        
  SetKeyName("pirate"); 
  SetId( ({ "pirate" }) );
  SetShort("an undead pirate");
  SetAdjectives( ({ "undead" }) );
  SetLong("This unsightly creature used to be a human pirate. Now undead, he is "
    "composed almost entirely of bone, save a few scraps of tattered, dead "     
    "skin, lacking any recognizable physical features.");                        

  SetSkill("enchantment", 100);
  SetInventory( ([             
    DOMAIN_INNERSEA "encounters/undead/cutlass" : "wield cutlass"
    ]) );                                                        
  SetCaptainAggressiveness(80);                                  
  SetProperty("pirate", "undead");                               
  SetShipWander(1);                                              
  SetDie("The pirate turns to dust and disperses on the wind."); 
  SetNoCorpse(1);                                                
  SetUndead(1);                                                  
  SetUndeadType("skeleton");                                     
  SetResistance(ALL_PHYSICAL|MAGIC, "medium");                   
  SetResistance(ALL_ELEMENTS,"high");                            
  SetResistance(POISON|HUNGER|DISEASE,"immune"); // SKELLINGTON  
  SetCurrency("imperials", 800);                                 

  SetMinLevel(125);
  SetMaxLevel(280);
  SetCombatStartVerb("backstab");

  SetBoarder(INNERSEA_ENCOUNTERS "undead/chainedzombie");
}    
