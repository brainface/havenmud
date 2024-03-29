#include <lib.h>
#include <daemons.h>
#include "../path.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Bank of Glimmerdin");
  SetLocalCurrency("nuggets");
  SetCurrencies(ECONOMY_D->GetCurrencies());
  SetLocalFee(0);
  SetNonLocalFee(5);
  SetTown("Glimmerdin");
  SetExchangeFee(0.05);
  SetKeyName("Duncan Tunnelbreaker");
  SetId( ({ "duncan", "tunnelbreaker", "banker", "glim_wander", "teller" }) );
  SetAdjectives( ({ "duncan", "tunnelbreaker", "glimmerdin" }) );
  SetShort("Duncan Tunnelbreaker, Banker of Glimmerdin");
  SetLong(
    "Duncan Tunnelbreaker is the dwarf most respected and still most "
    "hated in all of Glimmerdin.  It is he that controls the monetary "
    "policies, which often sets him at odds with the various merchant "
    "princes of the City Under the Mountain."
    );
  SetRace("dwarf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(35);
  SetMorality(-200);
}
