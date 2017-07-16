/* a hunting dog
    kyla 12-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("dog");
  SetShort("a hunting dog");
  SetLong("This well-bred dog looks to be a well treained hunting "
           "dog. He is quite large and appears very vicious.");
  SetId( ({"dog"}) );
  SetAdjectives( ({"hunting", "well-bred", "large"}) );
  SetGender("male");
  SetRace("dog");
  SetClass("animal");
  SetLevel(10);
  SetAction(6, "The dog sniffs you suspiciously.");
  }
