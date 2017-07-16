#include <lib.h>
inherit LIB_NPC;

int Phase;
int AdvancePhase();

static void create() {
  ::create();
  SetKeyName("cow");
  SetId( ({ "cow" }) );
  SetRace("cow");
  SetClass("animal");
  SetLevel(4);
  SetMorality(-200);
  SetGender("female");
  SetShort("a clever looking cow");
  SetAdjectives( ({ "clever", "looking" }) );
  SetLong("This clever looking cow appears to have something "
          "interesting and secret about it.");
  SetAction(50, (: AdvancePhase :) );
  Phase = 0;
}

int AdvancePhase() {
  if (!environment()) return 1;
  switch(Phase) {
    case 0:
      eventForce("trevor");
      SetInvis(1);
      break;
    case 1:
      eventForce("emote moos.");
      environment()->eventPrint("Where is the cow?  Hidden right now.");
      break;
    case 2:
      SetInvis(0);
      eventForce("emote is back from her magical journey.");
      break;
    }
  Phase++;
  if (Phase > 2) Phase = 0;
  return 1;
}
