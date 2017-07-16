#include <lib.h>
inherit LIB_MAYOR;
#include "../soleil.h"

static void create() {
   mayor::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Fossis");
   SetShort("Fossis, the mayor of Soleil");
   SetId( ({ "fossis","mayor","mayor of soleil" }) );
   SetAdjectives( ({ }) );
   SetLong("Fossis is a portly mayor with a slight pot belly sticking "
           "out of him.  He smiles cheerily and puffs a little from "
           "the exertion.");
   SetLevel(11);
   SetRace("muezzin");
   SetClass("valkyr");
   SetGender("male");
   SetTown("Soleil");
   SetTax(5*random(10)+20);
   SetLocalCurrency("cuicui");
   SetMorality(200);
   SetReligion("Eclat","Eclatish");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Kiee","Miserum" }) );
}
