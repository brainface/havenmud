//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("gruff goat");
  SetId( ( "goat" ) );
  SetAdjectives( ({"gruff", "mountain"}) );
  SetShort("a gruff mountain goat");
  SetLong(
    "This dun-colored goat seems more mature than most of "
    "his cousins and steps from rock to rock almost as if "
    "he is annoyed by it. His small horns curve downward, "
    "perhaps because of all the weighty thoughts that go "
    "through his goat mind each day. ");            
  SetRace("horse", "goat");
  SetClass("animal");
  SetGender("male");
  SetMorality(0);
  SetLevel(12);
  SetAction(6, ({ "!bah gruffly", "!hop gruffly"}));
}
