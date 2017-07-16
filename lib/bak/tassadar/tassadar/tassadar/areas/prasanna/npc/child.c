#include <lib.h>
#include "prasanna.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("child");
   SetId( ({ "child" }) );
   SetAdjectives( ({ "small" }) );
   SetShort("a small child");
   SetLong("This small child looks quite happy and innocent. He is fairly "
           "short with sandy hair. His eyes are a deep sapphire blue, and "
           "his features are soft. He has a single lock of hair that "
           "dangles down his forehead. ");
   SetLevel(2);
   SetMorality(15);
   SetGender("male");
   SetRace("elf");
   SetClass("fighter");
   SetAction(5, ({ "The child giggles and looks around." }) );
   SetCurrency("imperials", 10);
   SetFriends( ({ "widow" }) );
}
