#include <guildd.h>
#include <types.h>
#include <mudlib.h>
#include <material.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("chainmail");
  set_alt_name("mail");
  set_alias("shirt");
  set_short("ancient shirt of mail");
  set_long("\
This is a finely woven suit of chainmail that appears\n\
to have been crafted millenia ago.  It bears markings\n\
denoting it as the personal armour of Rath-Khan, the\n\
Lich King.\n");
  set_ac(30);
  set_new_type(TORSO);
  set_material(MAT_STEEL|MAT_SILVER);
  set_resistance(DAM_GOOD);
  set_guild_allow(MAGES);
  set_info("\
This is the suit of chainmail worn by Rath-Khan.\n\
Something seems odd about it.  It seems magical \n\
in nature.  You search through your mind, but \n\
cannot grasp the armour's secret.\n");
  set_warmth(20);
  set_weight(3);
  set_value(-1);
  replace_program(GEN_ARMOUR);
}
