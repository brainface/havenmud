/* Aramuuk -- 1998                                                 
   Leader mountain dwarfs. */                       
#include <lib.h>                                                   
#include "../path.h"                                               

inherit LIB_SENTIENT;                                                                       
static void create() {                                             
    sentient::create();                                            
    SetKeyName("dwarf");                                           
    SetId(({"dwarf"}) );                                           
    SetAdjectives( ({"mountain","barbarian","larger","larger"}) ); 
    SetShort("a larger looking wild dwarf");                       
    SetLong("This is a very large member of the wild mountain "+   
      "dwarves which are found in this area. Not only is he "+     
      "more massive than the other dwarves, he also carries "+     
      "himself so as to imply leadership. Unlike the other "+      
      "wild dwarves he seems much cleaner and his hair and beard "+
      "are well combed.");                                         
    SetRace("dwarf");                                              
    SetGender("male");                                             
    SetClass("fighter"); 
    SetLevel(random(7) + 15);                                          
    SetCurrency("nuggets",20+random(20));
    SetMorality(200);                                                
    SetFriends( ({ "dwarf" }) );  
    SetInventory( ([ 
    	OBJ+"tskin" : "wear skin",
			OBJ+"boots" : "wear boots",                     
			OBJ+"mace"  : "wield mace" ]) );                                                                                               
}    
