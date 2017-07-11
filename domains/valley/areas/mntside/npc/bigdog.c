/* Aramuuk 1998 */
#include <lib.h>                                                          
inherit LIB_NPC;                                                          
static void create() {                                                    
    npc::create();                                                          
    SetKeyName("dog");                                                      
    SetShort("a large dog");                                                  
    SetAdjectives( ({ "large", "male", }) );     
    SetLong("This unkempt dog appears larger than the other mountain dogs."); 
    SetId( ({ "dog" }) );                                                   
    SetRace("dog");                                                                                                                     
    SetClass("animal");                                                     
    SetLevel(6);  
    SetGender("male");                                                      
    SetFriends( ({ "dog" }) );   
}                                                                       

