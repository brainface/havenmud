#include <mudlib.h>
#include <race.h>
#include <types.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("wolf");
  set_alias("wolf");
  set_race("dog");
  set_long("\
This large furry death machine stands nearly a meter\n\
long at the shoulder.  It's grey fur is matted with\n\
the stains of living outdoors.\n");
  set_level(19);
  set_aggressive(20);
  set_al(-10,0);
  set_wc(10);
  set_con(14);
  add_dodge_bonus(15);
  load_a_chat(10, ({
    "The wolf snarls angrily!\n",
    "The wolf drops back before hurling itself back into combat.\n" }));
  set_gender(random(3));
  set_death_messages("\
The wolf begins to wander out of combat.  It then falls to the ground\n\
and goes through the last throws of death spasms.  The wolf dies.\n",
"The wolf begins to go into spasms, and death overtakes it.\n\
You have slain the wolf.\n");
  set_friends("wolf");
  load_chat(2,({
    "The wolf pads around "+this_object()->query_possessive()+" lair.\n",
    "The wolf devours some old bones.\n",
    "You think the wolf is watching you.\n"}));
  replace_program(MONSTER);  
}
