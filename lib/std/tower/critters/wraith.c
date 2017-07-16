#include <mudlib.h>
#include <types.h>
#include <race.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("wraith");
  set_short("a vengeful wraith");
  set_long("\
This ghostly form has been summoned from Rath-Khan's\n\
followers to avenge the tomb robbery!\n");
  set_level(40);
  set_race("undead");
  set_no_scare(1);
  load_a_chat(2,({
    "The wraith makes a hideous shreek!\n",
    "The wraith soars to the ceiling before diving back down to attack!\n",
    "You get a cold feeling as the wraith passes you by.\n"}));
  set_aggressive(1);
  add_dodge_bonus(20);
  set_gender(random(3));
  set_con(80);
  set_al(1200,1200);
  replace_program(MONSTER);
}
