#include <lib.h>
inherit LIB_ITEM;
inherit LIB_FEAR;

string caster;

static void create() {
  item::create();
  SetKeyName("fearmaker");
  SetId( ({ "fearmaker" }) );
  SetShort("Something that creates fear.");
  SetPreventGet("There is no fearmaker here.");
  SetLong("This thing makes fear...it should not be looked at.");
  SetFearType("horror of the magic in the area");
  SetResistLevel(10);
  SetFearLength(10);
  SetInvis(1);
}

void SetCaster(object ob) {
  caster = ob->GetKeyName();
}

void init() {
  if (this_player()->GetKeyName() == caster) return item::init();
  return fear::init();
}
