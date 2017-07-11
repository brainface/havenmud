#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("squirrel");
  SetShort("a small brown squirrel");
  SetId( ({ "squirrel", "small squirrel", "brown squirrel" }) );
  SetAdjectives( ({ "small", "brown" }) );
  SetRace("rodent");
  SetGender("male");
  SetLong(
    "This is a small furry brown squirrel. His eyes are "
    "a darker shade than his pelt and gleam wetly. "
    "A large bushy tail puffs up behind him and "
    "wiggles when he scurries about."
  );
  SetClass("animal");
  SetLevel(1);
  }
