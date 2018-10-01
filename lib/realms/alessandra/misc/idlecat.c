//  Idle Cat

#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();

  SetKeyName("cat");
    SetId( ({ "cat" }) );
    SetShort("an idle cat");
    SetLong("This cat serves no purpose, other than making "
        "sure Alessandra's client doesn't kick her off. He is "
        "therefore, affectionatly dubbed 'the idle cat'. He also "
        "is very cute. Squee, etc.");
    SetRace("cat");
    SetGender("male");
    SetClass("animal");
    SetLevel(500);
  SetAction(3, ({
    "!emote stretches languidly.",
    "!emote curls up on the cushion.",
    "!emote mewls softly.",
    "!emote is idly annoying.",
    "!emote cleans himself indescreetly.",
    "!emote chases thin air.",
    "!emote gets hair all over your clothes.",
    "!emote coughs up a hair ball.",
    "!emote attacks your big toe!",
     }) );
}
