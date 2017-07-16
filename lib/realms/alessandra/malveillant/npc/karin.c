/*  Portia   10-21-98
   A banker.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetKeyName("karin");
  SetShort("Karin, the bank teller");
  SetId( ({"teller", "karin", "woman", "dark-elf"}) );
  SetAdjectives( ({"bank"}) );
  SetLong("Karin looks like a very evil woman. Her long nose and "
      "huge glasses make her look more like a mean librarian than "
      "a trustworthy bank teller.");
  SetRace("dark-elf"); 
  SetTown("Malveillant");
  SetMorality(-1200);
  SetGender("female");
  SetInventory( ([
      MAL_OBJ + "/clothing/elf_skirt" : "wear skirt",
      MAL_OBJ + "/clothing/elf_blouse" : "wear blouse",
      ]) );
  
  SetClass("rogue");
  SetLevel(30);
  SetCurrency("roni",random(100) + 20);
  SetAction(5,
      "!speak I can take your money now.",
        );
  SetBankName("The Bank of Malveillant");
  SetLocalCurrency("roni");
  SetCurrencies( ({
     "roni", "chits",
     "imperials", "oros",
  }) );
  SetLocalFee(0);
  SetNonLocalFee(3);
  
  SetExchangeFee(0.01);
  }
