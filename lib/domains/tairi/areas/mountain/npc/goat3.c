//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("old goat");
  SetId( ( "goat" ) );
  SetAdjectives( ({"old", "mountain"}) );
  SetShort("an old mountain goat");
  SetLong(
    "This is an ancient mountain goat, his fur gone all white "
    "with old age. He moves shakily, but with the wisdom that "
    "comes with living on this mountain for many years. His "
    "yellowing horns look almost like fossilized shells, and "
    "twice as hard. ");            
  SetRace("horse", "goat");
  SetClass("animal");
  SetGender("male");
  SetMorality(0);
  SetLevel(14);
  SetAction(6, ({ "!bah weakly", "!hop shakily"}));
}
