#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("mare");
    SetId( ({"mare" }) ); 
    SetShort("a beautiful mare");
   SetAdjectives( ({ "beautiful","black" }) );
    SetLong("This black mare looks as if she has led a spoiled life, "
            "and seldom been ridden. Her entire appearance is that "
            "of royalty and exceptional breeding.");
    SetRace("horse");  
    SetClass("animal");
    SetGender("female");
    SetLevel(15);
  
}
