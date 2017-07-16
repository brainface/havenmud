#include <mudlib.h>
#include <material.h>
#include <types.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("a fine robe");
  set_ac(25);
  set_resistance(DAM_EVIL);
  set_warmth(25);
  set_short("a fine robe");
  set_long("\
This is a finely woven robe worn by the ceremonial\n\
guards of Rath Khan.\n");
  set_weight(3);
  set_alias("robe");
  set_alt_name("crobe");
  set_new_type(ARMOUR);
  set_material(MAT_CLOTH);
  set_value(-1);
  replace_program(GEN_ARMOUR);
}

