/* Aramuuk -- 1998                                                      
   One of my stock wild, mountain dwarfs. */                            
#include <lib.h>                                                        
#include "../path.h"                                                    

inherit LIB_NPC;                                                                                                                         
static void create() {                                                  
    npc::create();                                                 
    SetKeyName("dwarf");                                                
    SetId(({"dwarf"}) );                                                
    SetAdjectives( ({"mountain","barbarian"}) );                        
    SetShort("a rough looking wild dwarf");                             
    SetLong("This dwarf is a barbaric mountain dwarf. "+                
      "She has a distinctly unpleasant odor about her. "+               
      "Her hair, including her beard, is long and unkempt. "+           
      "Her clothing is nothing more than a basic animal skin tunic.");  
    SetRace("dwarf");                                                   
    SetGender("female");
    SetClass("priest");
    SetLevel(10);                                          
    SetCurrency("nuggets",10+random(20));
    SetMorality(200);                                           
    SetInventory ( ([ 
    		OBJ+"skin" : "wear armour",
				OBJ+"club" : "wield club" ]) );
}    
