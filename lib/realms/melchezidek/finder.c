#include <lib.h>

inherit LIB_ITEM;

string find(string what);

static void create() {
  ::create();
  SetKeyName("finder");
  SetShort("a finder mabob");
  SetId( ({ "finder" }) );
  SetLong("Something");
  SetAdjectives( ({ "dumb" }) );
//  add_action((: find :), "find");
}

void init() {
  ::init();
  add_action((: find :), "find");
}

string find(string what) {
	string *contents;
        contents = get_dir("/domains/");
        //environment(this_object())->eventPrint(implode(contents, ","));
        if (sizeof(what) == 0) return "Nope";
        foreach (string dom in contents) {
	  string *towns;
          towns = get_dir("/domains/" + dom + "/towns/");
          if (!sizeof(towns)) continue;
          if (member_array(lower_case(what), towns) != -1) {
		environment(this_object())->eventPrint(what + " is in " + dom);
		break;
          }
        }
        return "Stuff";
        //return "";
}

