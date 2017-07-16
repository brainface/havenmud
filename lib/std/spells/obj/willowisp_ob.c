#include <lib.h>
inherit LIB_ITEM;
int Life;
void destme();
static void create() {
item::create();
  SetKeyName("will o wisp");
  SetProperty("magic", "This is a temporarily docile will o' wisp. Don't "
    "follow it.");
  SetId( ({ "wisp", "will-o'-wisp","will-o-wisp"}) );
  SetAdjectives("will","o'","o");
  SetShort("a will o' wisp");
  SetLong("This ghostly little spirit is little more than a ball of "
    "phosphorescence and a tiny bit of malice. Occasionally, it bubbles "
    "slightly and you hear the faint sound of children crying." 
  );
  SetClass(3);
  SetMaterial( ({ "natural" }) );
  SetMass(0);
  SetValue(0);
  SetRadiantLight(30);
  set_heart_beat(1);
  Life = 240;
}

void heart_beat() {
  Life--;
  if (!Life) destme();
  }

void destme() {
  if (environment(this_object())) {
    message("system",
      "A will o' wisp flutters away suddenly, something like the laughter "
      "of a child following it into the distance.",
      environment(this_object()) );
    }
    eventDestruct();
}

