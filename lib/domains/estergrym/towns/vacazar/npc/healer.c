// Coded by Zeratul
// 3-22-2000

#include <lib.h>
#include "../vacazar.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("sehara");
  SetFriends( ({"sarakar"}) );
  SetGender("female");
  SetLong(
     "This is the local healer for the town. She has a calm appearance "
     "on her face, suggesting she could help anyone if paid well enough.");
  SetShort("Sehara the healer");
  SetRace("skaven");
  SetId( ({"healer","sehara"}) );
  SetReligion("Skadar");
  SetTown("Vacazar");
  SetClass("priest");
  SetLevel(13);
  SetCurrency("vacari",random(120));
  SetLocalCurrency("vacari");
  SetFees( ([
    "resurrect" : 100,
    "magic" : 10,
    "stamina" : 1,
    "health" : 3,
    "restore" : 50,
  ]) );
}
