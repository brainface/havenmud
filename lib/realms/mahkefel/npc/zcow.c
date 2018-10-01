#include <lib.h>
inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("totally a zombie cow");
  SetAdjectives(({"zombie","totally","a"}));
  SetLong("This is not your average milking cow. Honestly, it doesn't smell any worse, though.");
  SetRace("cow");
  SetGender("female");
  SetClass("animal");
  SetKeyName("cow");
  SetId(({"cow","zombie"}));
  SetUndead("zombie");
  SetAction(20,({"!emote moos painfully.","!say brains?","!emote chews on something that is probably not cud."}));
  SetLevel(15);
}

