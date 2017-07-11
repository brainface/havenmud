//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("large yeti");
  SetId( ( "yeti" ) );
  SetShort("a large yeti");
  SetLong(
    "This giant-like creature dwells in the mountains away "
    "from scrutinizing eyes. The yeti is covered in thick, "
    "matted fur that helps him blend almost seamlessly with "
    "the mountain environment, and he seems to be even bigger "
    "than others of his kind. His lower jaw is stained pink, "
    "as if he has recently enjoyed feasting on the haunch of "
    "a happy goat or two.");            
  SetRace("giant");
  SetClass("fighter");
  SetGender("male");
  SetMorality(-200);
  SetLevel(40);
  SetAction(6, ({ "!growl loudly", 
    "!emote kicks a stray goat over the edge of the mountain.",
    "!emote watches you closely."}));
}
