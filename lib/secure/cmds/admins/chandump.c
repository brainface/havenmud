#include <lib.h>
#include <daemons.h>

#define DUMPDIR "/realms/" + this_player()->GetKeyName() + "/chandump/"

inherit LIB_DAEMON;

mixed cmd(string arg)
{
  object who = this_player();
  string* chans = copy(who->GetChannels());
  mixed* ts = ({ });
  int tmp = 0;

  if (!securep(this_player())) return "No.";
  if (arg)
  {
    if (member_array(arg, chans) == -1) return "Can not dump channel you are "
                                               "not listening to.";
    else chans = ({ arg });
  }

  if ((tmp = file_size(DUMPDIR)) != -2)
  {
    if (tmp != -1) return "Can not finish while file \"chandump\" is in your "
                          "home directory.";
    if (!mkdir(DUMPDIR)) error("Can not create directory " + DUMPDIR);
  }

  // Just easier to make sure there are no subdirs at all to worry about
  foreach (string file in get_dir(DUMPDIR))
  {
    if (file_size(DUMPDIR + file) == -2) return "Dumbass!  Get rid of the "
      "subdirectories in " + DUMPDIR + " and THEN we'll talk.";
  }

  foreach (string ch in chans)
  {
    if (!CHAT_D->GetHistory(ch)) continue;
    foreach (mixed* line in copy(CHAT_D->GetHistory(ch)))
    {
      ts = localtime(line[0]);
      if (!write_file(DUMPDIR + ch, sprintf("%02d/%02d/%04d %02d:%02d:%02d -- %s\n",
        ts[4]+1, ts[3], ts[5], ts[2], ts[1], ts[0], strip_colours(line[1]))))
        error("Can not write to " DUMPDIR + ch);
    }
  }
  return "Done.";
}
