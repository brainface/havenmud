#include <lib.h>
inherit LIB_DAEMON;

static void create() {
  ::create();
}

mixed cmd(string dir) {
  mixed *subdirs =({ });
  mixed *files = ({ });
  
  if (!dir) return "Unload which directory?";
  if (!sizeof(subdirs = get_dir(dir))) {
    subdirs = get_dir(dir + "/");
    if (!sizeof(subdirs)) return "Sorry, what directory?";
  }
  foreach(string subdir in subdirs) {
    files = get_dir(dir + subdir + "/*.c");
    if (!sizeof(files)) continue;
    foreach(string file in files) {
      object ob = load_object(dir + subdir + "/" + file);
      if (ob) ob->eventDestruct();
    }
  }
  return dir + " unloaded.";
}

    
  