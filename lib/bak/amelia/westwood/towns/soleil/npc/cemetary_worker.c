// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "../soleil.h"

static void create() {
   npc::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("cemetery worker");
   SetShort("a cemetery worker");
   SetId( ({ "worker" }) );
   SetAdjectives( ({ "cemetery" }) );
   SetLong("The tired face of this meuzzin looks around the cemetery "
           "wearily, thinking of how much work it takes to keep the "
           "place nice and clean.");
   SetRace("muezzin");
   SetGender("male");
   SetClass("valkyr");
   SetLevel(12);
   SetCurrency("cuicui",random(50)+75);
   SetMorality(75);
   SetReligion("Eclat","Eclatish");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetery worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
