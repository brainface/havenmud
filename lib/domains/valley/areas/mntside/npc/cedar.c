/* Aramuk 1997 -- Shaman for wild Dwarves                                                       
*/                                                                   
#include <lib.h>                                                     
#include "../path.h"                                               
inherit LIB_NPC;                                                  

static void create() {                                               
    npc::create();
    SetKeyName("Cedar");                                                
    SetShort("Cedar the Wild Shaman");                            
    SetId( ({"cedar", "dwarf", "shaman"}) );                             
    SetAdjectives( ({ "wild", "dwarven", }) );                             
    SetLong("Here stands a stout, wizened dwarf who has many tattoos "+
      "covering his compact frame. He sits here contemplating the "+
      "bright blue flames he has conjured.");                  
    SetRace("dwarf");                                                  
    SetGender("male");                                                                                                
    SetCombatAction(80, ({                                              
	    "!cast shock",    
	    "!cast holy shield",                                                    
      }) );                                                                                    
    SetClass("shaman"); 
    SetLevel(random(3) + 15);    
    SetSkill("shock magic",  30, 1);
    SetCurrency("nuggets",30+random(20));
    SetMorality(1000);                                                     
    SetInventory( ([ 
    	OBJ+"club" : "wield club",
			OBJ+"skin" : "wear skin"                                                  
      ]) );                                                  
    SetReligion("Kylin");                                   
    SetSpellBook( ([                                                   
      	"shock" 	    : 100, 
      	"holy shield" : 100,                                                    
      ]) );                                    
} 
