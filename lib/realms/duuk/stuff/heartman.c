#include <lib.h>
#define HB 1
inherit LIB_NPC;

int TalkTimer;
static void create() {
  ::create();
  SetKeyName("Probably Not Duuk");
  SetShort("a guy that is Probably Not Duuk");
  set_heart_beat(HB);
  SetRace("elf");
  SetGender("male");
  SetId( ({ "dude", "guy" }) );
  SetAdjectives( ({ "useful", "helper" }) );
  TalkTimer = 1;
}

void heart_beat() {
  if (environment()) {
    TalkTimer++;
    if (TalkTimer > 120) {
      TalkTimer -= 120;
      environment()->eventPrint(".");
      }
    }
  ::heart_beat();
}
