#include <lib.h>
#include <daemons.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("zombie");
  SetShort("a zombie");
  SetDie("The zombie crumbles into dust.");
  SetNoCorpse(1);
}