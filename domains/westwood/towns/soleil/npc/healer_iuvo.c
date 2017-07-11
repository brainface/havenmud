#include <lib.h>
inherit LIB_HEALER;
#include "../soleil.h"

static void create() {
   healer::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Iuvo");
   SetShort("Iuvo the healer");
   SetId( ({ "iuvo","healer","iuvo the healer","male","muezzin" }) );
   SetAdjectives( ({ }) );
   SetLong("Iuvo has a patiently calm look to his face, ready to "
           "heal with steady hands and a rational mind.  He "
           "smiles a wry smile beneath his fur.");
   SetGender("male");
   SetRace("muezzin");
   SetClass("priest");
   SetSkill("melee combat",1,2);
   SetLocalCurrency("cuicui");
   SetLevel(25);
   SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
    ]) );
   SetMorality(200);
   SetReligion("Eclat","Eclat");
   SetTown("Soleil");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Fossis","Kiee","Miserum" }) );
}
