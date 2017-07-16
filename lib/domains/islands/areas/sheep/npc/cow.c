#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetShort("a well-fed cow");
    SetLong(
      "This cow appears to be bored with its contented life of chewing, eating, and giving milk."
      );
    SetRace("cow");
    SetGender("female");
    SetClass("animal");
    SetKeyName("well-fed cow");
    SetAdjectives( ({ "well", "fed", }) );
    SetId( ({"cow"}) );
    SetLevel(8);
    SetAction(5, ({
      "The cow bows its head and chews some of the well-chewed grass.",
      "!moo",
    }) );
}
