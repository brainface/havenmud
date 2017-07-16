#include <lib.h>
#include <domains.h>
inherit LIB_SHIPCAPTAIN;

static void create() {
  ::create();
  SetKeyName("ferry captain");
  SetLimit(1);
  SetShort("a ferry boat captain");
  SetId( ({ "ferrycaptain", "captain" }) );
  SetAdjectives( ({ "ferry", "boat" }) );
  SetRace("human");
  SetClass("fighter");
  SetClass("sailor");
  SetSkill("sailing", 1, 1);
  SetLevel(20);
  SetGender("male");
  SetLong("The ferry boat captain looks perfectly bored in his work.  So bored that "
          "sympathy for him comes fast and hard to anyone who views his plight.");
  SetShipWanderPath(SOUTHERN_COAST_TOWNS "haven/room/wharf", AVERATH_ISLAND "-2,5,0");
  SetFirstCommands("board ferry");
  SetDirection(1);
}
