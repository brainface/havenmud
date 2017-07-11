#include <lib.h>
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("brown cow");
    SetId( ({ "cow", "brown cow" }) );
    SetShort("a brown cow");
    SetLong("The cow is obviously oblivious to the battle waging nearby, "
          "as is evidenced by the way she calmly chews her cud.");
    SetRace("cow");
    SetClass("animal");
  	SetLevel(3);
    SetGender("female");
}
