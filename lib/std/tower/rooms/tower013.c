#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  add_clone(CRITS+"/librarian");
  if (arg) return;
  set_terrain(TER_INSIDE);
  set_short("northwest level 2");
  set_long("\
You are surrounded by books of all kinds.  This seems \n\
to have been the library.  You see mahogany desks with\n\
reams of paper piled on top, and also see that the books\n\
seem to have withstood the test of time on the shelves.\n");
  add_look(({"desk","desks"}),"\
This is a large mahongany desk that seems to have been used \n\
for study and research.\n");
  add_look(({"shelves","shelf"}),"\
The shelves are old yet taken care of, you wonder who could\n\
be keeping them up all these years.\n");
  add_look(({"book","books","paper","papers"}),"\
You don't get far searching on your own.  Maybe you could \n\
ask for help?\n");

  add_exit("south",TOWER+"/tower021");
}


void init() {
  ::init();
  add_action("shout","shout");
  add_action("say","say");
  add_action("whisper","whisper");
}

int shout(string str) {
  object ob;
  ob = present("librarian");
  if (ob) {
    ob->attack_object(TP);
    TP->attack_object(ob);
    write("The librarian doesn't take kindly to shouting in here!\n");
    say(TP->NAME+" has annoyed the Librarian with a shout!\n");
    return 0;
  }
  return 0;
}

int whisper(string str) {
  object ob;
  ob = present("librarian", ENV(TP));
  if (ob) {
    if (str == "librarian help" || str == "man help" || str == "figure help") {
      write("The librarian's eyes glitter momentarily, but soon lose \
their vigor.\n");
      say(TP->NAME+" recieves a kind smile from the Librarian.\n");
      return 1;
    } else {
        say("The Librarian smiles at "+TP->NAME+".\n");
        write("The Librarian smiles at you.\n");
        return 0;
      }
      return 0;
  }
}

int say(string str) {
  object ob;
  ob = present("librarian");
  if (ob) {
    ob->attack_object(TP);
    TP->attack_object(ob);
    write("As you open your mouth, the librarian attacks!\n");
    return 1;
  }
  return 0;
}


