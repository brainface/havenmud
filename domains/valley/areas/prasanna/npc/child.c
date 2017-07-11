#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("child");
   SetId( ({ "child" }) );
   SetAdjectives( ({ "small" }) );
   SetShort("a small child");
   SetLong("This small child looks quite happy and innocent. He is having "
           "quite a good time playing with his toys. ");
   
   SetGender("male");
   SetRace("elf");
   SetClass("rogue");
   SetLevel(2);
   SetMorality(15);
   SetAction(5, ({ "The child giggles and looks around." }) );
   SetCurrency("imperials",10);
   SetFriends( ({ "widow" }) );
}



/* Approved by Zaxan on Wed Apr  1 03:40:58 1998. */
