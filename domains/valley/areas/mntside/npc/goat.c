/* Aramuuk 1998 */
#include <lib.h>                                                          
inherit LIB_NPC;                                                          
static void create() {                                                    
    npc::create();                                                          
    SetKeyName("goat");                                                      
    SetShort("a mountain goat");                                                  
    SetLong("This is a large mountain goat. His horns are long and "+
      "deadly. There are two things which come to mind when looking "+
      "at this beast: first, he looks very strong; second, it looks as "+
      "if your weapon could easily get tangled in his horns."); 
    SetId( ({ "goat" }) );                                                   
    SetAdjectives( ({ "mountain", "large", }) );                             
    SetRace("sheep");                                                                                                                     
    SetClass("animal");  
    SetSkill("disarm");                                                   
    SetLevel(7);  
    SetGender("male");
    SetCombatAction(10, ({"!disarm", }) );
    AddStatLevel("strength", 45);
    SetFriends( ({ "goat" }) );                                                
} 
