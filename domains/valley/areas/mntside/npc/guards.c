/* Aramuuk -- 1998
   One of the guardian mountain dwarfs. */
#include <lib.h>                                                            
#include "../path.h" 

inherit LIB_NPC;                                                                                       

static void create() { 
    npc::create();                                                     
    SetKeyName("dwarf");                                                     
    SetId(({"dwarf"}) );                                             
    SetAdjectives( ({"mountain","barbarian","wild","wild looking" }) );
    SetShort("a wild looking dwarf");                                         
    SetLong("This dwarf is a barbaric mountain dwarf. "+
      "However, he is not a commoner amongst his people. He is "+
      "a highly trained personal body guard for his leader.");                   
    SetRace("dwarf");                                                         
    SetGender("male");                                                                                               
    SetClass("fighter");
    SetLevel(random(5) + 10);   
    SetCurrency("nuggets",15+random(15));
    SetMorality(200);
    SetInventory( ([ 
    	OBJ+"tskin" : "wear skin",
			OBJ+"boots" : "wear boots",
			OBJ+"axe"   : "wield axe" ]) );                                                           
    SetFriends( ({ "dwarf" }) );  
}  
