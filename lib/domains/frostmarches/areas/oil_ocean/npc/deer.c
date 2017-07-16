//Illura@haven
//Nov 2010
#include <lib.h>
#include "../oil.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("deer");
  SetShort("a mutated deer");
  SetId( ({"deer"}) );
  SetAdjectives( ({ "deer" }) );
  SetRace("deer");
  SetClass("animal");
  SetLong(
    "This animal hobbles about on muscular legs, for a deer. Its "
    "fur is a strange green hue, and spittle lines its lips. There "
    "is clearly something wrong with the deer, which seems "
    "very agitated in your presence."
    );
  SetGender("male");
  SetLevel(4);
 SetAction(5, ({
    "!emote bounds away quickly.",
    "!emote huffs and snuffles at the vegetation, searching for food."
  }) );
}
