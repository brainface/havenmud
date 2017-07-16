#include <lib.h>
inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("totally a zombie cow");
  SetAdjectives(({"zombie","totally","a"}));
  SetLong("Imagine a zombie cow, in your head. Now imagine you're looking at a really good description of that, but better. ");
  SetRace("cow");
  SetGender("female");
  SetClass("animal");
  SetKeyName("cow");
  SetId(({"cow","zombie"}));
  SetUndead("zombie");
  SetAction(5,({"!emote moos painfully.","!say brains?","!emote chews on something that is probably not cud."}));

  SetLevel(15);
}


/** Approved by Alessandra at Tue Dec  3 15:45:57 2013. **/
