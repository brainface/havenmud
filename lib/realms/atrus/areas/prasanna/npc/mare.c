#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("mare");
    SetId( ({"mare" }) ); 
    SetAdjectives( ({ "beautiful","black" }) );
    SetShort("a beautiful mare");
    SetRace("horse");
    SetGender("female");
    SetClass("animal");
    SetLevel(15);
    SetLong("This black mare looks as if she has led a spoiled life, "
            "and seldom been ridden. Her belly is plump, and her legs "
            "show very little muscle tone. Her entire appearance is that "
            "of royalty and exceptional breeding. Her eyes are sad, filled "
            "with a longing for youthful days.");
}
