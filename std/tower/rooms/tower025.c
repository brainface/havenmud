#include <mudlib.h>
#include <perms.h>
#include "../rooms.h"
inherit ROOM;
int grace;
object ob;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS + "/rath");
  grace=0;
  if (arg) return;
  set_light(3);
  set_terrain(TER_INSIDE);
  set_short("Throne Room");
  set_long("\
This brightly lit chamber is the audience chamber\n\
of Rath-Khan.  Looking around, you see more captured\n\
banners and flags, in addition to paintings and \n\
artwork.  The audience chamber shows the trappings of \n\
wealth in a way that stuns your mind.\n");

  add_look(({"flags","banners"}),"\
These seem to be the captured flags of nobles foolish\n\
enough to not heed Rath-Khan.\n");

  add_look(({"paintings","artwork"}),"\
These seem to be fancy decorations stolen long ago.\n");

  add_exit("down", TOWER + "/tower017");
}

status down_hook() {
  if (IS_APPLICANT(TP)) { return 0; }
  if (!present("rath")) { return 0; }
  if (present("emperor") && grace==0) {
    write("Rath-Khan has not dismissed you yet!\n");
    say(TP->NAME+" tried to leave but was 'convinced' to stay.\n");
    return 1;
  }
  if (TP->query_attack() == find_living("rath") && present("emperor")) {
    tell_room(ENV(TP), "Rath Khan bellows \"Trying to LEAVE, "+TP->NAME+"?\n");
    return 1;
  }
  return 0;
}

void init() {
  ::init();
  add_action("down","down");
  add_action("grovel","grovel");
  add_action("beg","beg");
  add_action("worship","worship");
}

int down() {
  if (TP->query_attack()) {
    if (TP->query_attack() == find_living("rath")) {
      tell_room(ENV(TP),"Rath Khan bellows, \"Trying to LEAVE, "+TP->NAME+"?\"\n");
      return 1;
    }
  }
  if (present("emperor") && grace==1) {
    write("You leave via the stairs.\n");
    say(TP->NAME+" darts down the stairs quickly.\n");
    move_object(TP, TOWER+"/tower017");
    command("look",TP);
    grace = 0;
    return 1;
  }
  return 0;
}

int grovel(string str) {
  if (str == "rath" || str == "emperor" || str == "khan") {
    write("You shamelessly grovel before Rath-Khan.\n\
He allows you to flee.\n");
    say(TP->NAME+" grovels before Rath-Khan.\n\
The Emperor makes a dismissive gesture toward "+TP->NAME+".\n");
    grace = 1;
    return 1;
  }
  return 0;
}

int worship(string str) {
  if (str=="rath" || str == "emperor" || str == "khan" ) {
    write("You worship Rath-Khan. He makes a gesture at you in dismissal.\n");
    say(TP->NAME+" worships Rath-Khan.  The Emperor nods in amusement.\n");
    grace = 1;
    return 1;
  }
  return 0;
}

int beg(string str) {
  if (str == "rath" || str == "emperor" || str == "khan" ) {
    write("You beg for your life.\n");
    write("He will allow you to leave.\n");
    say(TP->NAME+" begs Rath-Khan to spare "+ TP->POSS + " life.\n\
The Emperor dismisses "+TP->NAME+" with a nod.\n");
    grace = 1;
    return 1;
  }
  return 0;
}
