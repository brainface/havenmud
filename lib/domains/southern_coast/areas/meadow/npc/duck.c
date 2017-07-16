// A yellow duck thats pigeon toed. How original!
// For Platypus Bay
// Urien@Haven 06JUL08

#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("duck");
    SetId( ({"yellow duck","duck" }) ); 
    SetShort("a yellow duck");
    SetLong(
            "Small feathers coat the ducks tiny body covering her wings "
            "and tail. Her black eyes stand out of her small head rather oddly. "
            "The webbed feet which support her body have tiny talons creeping "
            "out of her orange toes. A small orange bill with tiny holes on each "
            "side resemble a nose."
            );
    SetRace("bird");
    SetGender("female");
    SetClass("animal");
    SetLevel(2);
    SetMorality(1);
    SetAction(15, ({
    "!emote flutters her wings loudly.",
    "!emote quacks."
  }) );
  }

