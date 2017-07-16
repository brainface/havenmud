#include <lib.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("elven captain");
  SetShort("an elven captain");
  SetId( ({ "captain", "elf" }) );
  SetAdjectives( ({ "elven", }) );
  SetRace("elf");
  SetTown("Haven");
  SetClass("viking"); /* I'm cheating here. */
  SetLevel(80);
  SetLong(
    "This elf is a contemplative sort, sailing the seas for the glory of the Elves."
    );
  SetGender("male");
  SetCaptainAggressiveness(0);
  SetShipWimpy(40);
  SetShipWander(1);
  SetCurrency("imperials", 12000);
  SetFriends( ({ "elf marine" }) );
}
