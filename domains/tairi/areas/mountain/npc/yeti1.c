//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("yeti");
  SetId( ( "yeti" ) );
  SetShort("a yeti");
  SetLong(
    "This giant-like creature dwells in the mountains away "
    "from scrutinizing eyes. The yeti is covered in thick, "
    "matted fur that helps him blend almost seamlessly with "
    "the mountain environment, and his squashed face looks "
    "nearly capable of expressing feelings other than rage. "
    "He seems to even have an affinity for the goats that "
    "share the mountainside.");            
  SetRace("giant");
  SetClass("fighter");
  SetGender("male");
  SetFirstCommands( ({ "guard northeast" }) );
  SetMorality(100);
  SetLevel(30);
  SetAction(6, ({ "!growl loudly", 
    "!emote pets a stray goat fondly.",
    "!emote eyes you warily.",
    "!emote attempts to hide against a rock."}) );
}
