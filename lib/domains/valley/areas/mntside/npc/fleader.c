/* Aramuuk -- 1998                                            
   Leader of the mountain dwarfs' woman. */                  
#include <lib.h>                                              
#include "../path.h"                                          

inherit LIB_SENTIENT;                                         
static void create() {                                        
    sentient::create();                                       
    SetKeyName("dwarf");                                      
    SetId(({"dwarf"}) );                                      
    SetAdjectives( ({"mountain","barbarian","larger","larger"}) );
    SetShort("a larger looking wild dwarf");                  
    SetLong("This female dwarf is much larger than many of the "+
      "other wild dwarves on the mountain side. Unlike the "+ 
      "other dwarves, however, she is very clean and presents "+
      "a well kept physical appearance. One might claim that, "+
      "she is extremely attractive, even for a dwarf!");      
    SetRace("dwarf");                                         
    SetGender("female");                                                                             
    SetClass("fighter"); 
    SetSkill("melee combat",1,2);
    SetLevel(random(5) + 15);   
    SetCurrency("nuggets",20+random(30));
    SetMorality(200);                                           
    SetFriends( ({ "dwarf" }) );  
    SetInventory( ([ 
    	OBJ+"dress" : "wear dress",
			OBJ+"crown" : "wear crown",
			OBJ+"boots" : "wear boots"
			]) );                                                                         
}                                                             
