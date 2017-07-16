#include <lib.h>
#include "../glim.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("Samik");
  SetGender("male");
  SetTown("Glistendin");
  SetShort("Samik the Healer");
  SetLong("Samik is the healer of dwarven populace. "
          "He brings healing to those who have fallen into injury "
          "and pain, and his very presence brings a sense of calm.");
  SetRace("dwarf");
  SetId( ({ "Samik", "healer" }) );
  SetReligion("Kylin", "Kylin");
  SetClass("cleric");
  SetSkill("melee attack", 1, 1);
  SetLevel(50);
  SetCurrency("glims", random(5));
  SetLocalCurrency("glims");
  SetFees( ([
    "resurrect" : 20,
    "stamina"   : 1,
    "health"    : 1,
    "restore"   : 5,
    ]) );
  SetMorality(800);
 }

mixed eventAsk(object who, string str) {
   if ( who->GetReligion() != "Kylin" ) {
    eventForce("speak My lord does not favor your recovery.");
   return 1;
 }
  ::eventAsk(who, str);
}

