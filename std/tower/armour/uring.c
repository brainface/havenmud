#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("ring");
  set_short("a beautiful diamond ring");
  set_long("|WK0\
This ring is dazzling in its display of wealth\n\
and pagentry.\n");
  set_value(-1);
  set_new_type(RING);
  set_material(MAT_GOLD|MAT_GEM);
  replace_program(GEN_ARMOUR);
}
