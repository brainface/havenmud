#include <mudlib.h>
#include <race.h>
#include <types.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("librarian");
  set_alias("figure");
  set_alt_name("skeleton");
  set_race("undead");
  set_level(22);
  set_short("a robed figure");
  set_long("\
This is the master librarian for Rath-Khan's library.\n\
He seems to be noiselessly going about his work.\n");
  add_money(random(500));
  set_gender(1);
  load_chat(2,({
    "The Librarian shuffles some books about.\n",
    "The Librarian glares at an imperceptable sound.\n",
    "The Librarian places some books on the shelves.\n",
    "The Librarian looks at you.\n"}));
  set_friends("skeleton");
  set_al(-300,600);
  replace_program(MONSTER);
}
