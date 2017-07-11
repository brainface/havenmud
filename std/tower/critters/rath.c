#include <mudlib.h>
#include <race.h>
#include "../rooms.h"
#include <types.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("rath");
  set_level(99);
  set_al(-1500,1500);
  set_switch_chance(75);
  set_psi_resistance(120);
  set_magic_resistance(60);
  set_con(240);
  set_no_scare(1);
  set_wc(80);
  add_money(4000);
  set_short("the Emperor Rath-Khan");
  set_alias("emperor");
  set_alt_name("khan");
  enable_player_commands();
  set_race("undead");
  set_gender(1);
  set_long("\
This is the Ruler of this place.  Rath-Khan is a huge\n\
warrior of the type of you have never seen before.\n\
You stand in awe of his form.\n");
set_size(SIZ_LARGE);
  make_object("crown",ARMR+"/crown");
  make_object("amulet",ARMR+"/evil_amulet");
  make_object("mace",WPNS+"/rath_mace");
  command("wield mace");
  command("wear amulet");
  command("wear crown");
  load_cmd(2, ({
    "say Worm!  Worship me!",
    "say You will never get out of here alive!",
    "say Grovel before me, you worthless filth!",
    "say Begging for your life might save you, if I so decide!",
    "say You should have no hope of surviving!",
    "glare $N",
    "say Bah, you are a worthless degenerate.",
    "say my empire will rise again!" }) );
  replace_program(MONSTER);
}
