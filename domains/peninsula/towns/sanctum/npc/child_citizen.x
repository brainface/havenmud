#include <lib.h>
#include "../rome.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("child");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetClass("merchant");
  SetGender(random(2) ? "male" : "female");
  SetShort("a small " + GetGender() + " child");
  SetId( ({ "child", "wander" }) );
  SetAdjectives( ({ "small", GetGender() }) );
  SetMorality(5);
  SetLong(
     "This young child looks to be a content young person. Doing what children do, without a care "
     "in the world, this child plays carefree, laughing and smiling. "
  );
  SetLevel(1);
  SetLimit(4);
  SetWander(5);
}
