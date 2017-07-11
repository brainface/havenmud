// Amelia@Haven

#include <lib.h>
inherit LIB_TELLER;
#include "../soleil.h"

static void create() {
   teller::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Aegri Portare");
   SetShort("Aegri Portare, the banker");
   SetId( ({ "aegri","bank teller","teller","banker" }) );
   SetLong("Aegri works for Soleil's bank as a teller, here to exchange "
           "currencies and hold your money until you want it.  She "
           "also sends out the mail.");
   SetRace("muezzin");
   SetGender("female");
   SetClass("merchant");
   SetLevel(11);
   SetCurrency("cuicui",random(350)+2);
   SetBankName("First Bank of Soleil");
   SetLocalCurrency("cuicui");
   SetCurrencies( ({ "cuicui","rounds","rupies","nuggets" }) );
   SetLocalFee(0);
   SetNonLocalFee(10);
   SetExchangeFee(0.000005);
   SetTown("Soleil");
   SetMorality(100);
   SetReligion("Eclat","Eclat");
   SetFriends( ({ "Dulcae","Tia","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
