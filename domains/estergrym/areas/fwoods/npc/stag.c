#include <lib.h>  // Needs to be included in all files
#include "../vaashan.h"
inherit LIB_NPC;
static void create() {
  ::create();

  SetKeyName("stag");
  SetId( ({"stag","deer"}) );
  SetAdjectives( ({"huge","white","majestic"}) );
  SetShort("a huge white stag");
  SetLong(
    "Standing at nearly two meters high, this majestic stag has a lithe, "
    "compact body and long, powerful legs. His coat is snow-white, and "
    "a large rack of antlers grows from his head. He looks about with "
    "confidence, and seems to have little fear of any potential opponent."
    );
  SetRace("deer");
  SetClass("animal");
  SetLevel(70);
  SetGender("male");
  SetAction(5, ({
    "The stag eats a few leaves from one of the trees.",
    "The stag stops stock-still, and looks about for danger.",
    "!sniff"
    }) );
  SetMeleeAttackString("antlers");
  SetCombatAction(10, ({
    "The stag charges foward at you with sharpened antlers.",
    }) );
  SetCorpseItems( ([VAAS_OBJ + "antlers" : 1]) );
}