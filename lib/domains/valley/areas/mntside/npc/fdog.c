/* Aramuuk 1998 */
#include <lib.h>                                                       
inherit LIB_NPC;                                                       
static void create() {                                                 
    npc::create();                                                     
    SetKeyName("dog");                                                 
    SetShort("a skinny dog");                                           
    SetLong("This is a skinny, but tough appearing mountain dog.");    
    SetAdjectives( ({ "skinny", "female", }) );  
    SetId( ({ "dog" }) );                                              
    SetRace("dog");                                                                                                         
    SetClass("animal");                                                
    SetLevel(5);  
    SetGender("female");                                               
    SetFriends( ({ "dog" }) );   
} 
