#include <lib.h>
#include "../argoth.h"
inherit LIB_TELLER;
static void create() {
    teller::create();
    SetBankName("Argoth Bank");
    SetLocalCurrency("khuca");
    SetCurrencies( ({
    "imperials", "khuca", "rounds", "chits", "cuicui", "dinar"
}) );
    SetLocalFee(0);
    SetNonLocalFee(5);
    SetTown("Karak");
    SetExchangeFee(0.05);
    SetKeyName("ouphe");
    SetShort("Ouphe the Teller");
    SetId( ({ "ouphe the teller", "ouphe", "teller"}) );
    SetLong("Ouphe is the teller at the Argoth Bank.  He was also the project "
    "foreman while the bank was being built.  He is big, tough, and knows "
    "everything there is to know about money and currencies.");
    SetRace("orc");
    SetGender("male");
    SetClass("rogue");
    SetLevel(11);
    SetCurrency("khuca", random(200));
    SetInventory( ([
]) );
}
