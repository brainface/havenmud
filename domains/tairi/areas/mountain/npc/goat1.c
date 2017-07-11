//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("happy goat");
  SetId( ( "goat" ) );
  SetAdjectives( ({"happy", "mountain"}) );
  SetShort("a happy mountain goat");
  SetLong(
    "This is a sure-footed little mountain goat, who seems "
    "very happy in his environment as he prances from one "
    "outcropping to the next with no fear at all. He has "
    "short grey fur and tiny curved horns built for ramming "
    "enemies, but his life is so good that he rarely has to "
    "resort to such tactics.");            
  SetRace("horse", "goat");
  SetClass("animal");
  SetGender("male");
  SetMorality(0);
  SetLevel(10);
  SetAction(6, ({ "!bah happily", "!hop happily"}));
}
