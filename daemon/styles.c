/*  The combat styles daemon */
#include <lib.h>
#include <std.h>
inherit LIB_DAEMON;

mapping Styles;
int eventLoadStyles();

static void create() {
  ::create();
  SetNoClean(1);
  Styles = ([ ]);
  eventLoadStyles();
}

int eventLoadStyles() {
  string *dir = get_dir(STD_STYLE);
  object tmp;

  foreach(string filename in dir) {
    if (tmp = load_object(STD_STYLE + filename)) {
      Styles[tmp->GetStyleName()] = tmp;
      }
    }
  return sizeof(Styles);
}

        


object GetStyle(string style) {
  if (!Styles[style]) eventLoadStyles();
  return Styles[style];
 }

string *GetStyles() {
  return (keys(Styles));
 }
