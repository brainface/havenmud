#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("ghostrider");
  SetShort("a nicolas cage");
  SetShort("a nicolas cage");
  SetId( ({ "nic", "nic cage", "nicolas", "cage" }) );
  SetAdjectives( ({ "pot", "bellied", "canadian" }) );
  SetRace("human");
  SetClass("cavalier");
  SetLevel(5);
  SetGender("male");
  SetLong("A wild nicolas cage appears!");
  SetCurrency("imperials", random(2)+1 );
  SetAction(10, ({"!emote swats away the bees.", "!emote 's skull ignites.", 
  "!emote defeats john malcovich's cunning plan.", "!emote steals historic documents"}));
}

