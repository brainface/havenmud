#include <daemons.h>

mixed cmd(string args) {
  if(!args) {
    return ("Correct syntax: siteban <ip>\n");
    }
  BANISH_D->AddBannedSite(args);
  if (member_array(args, BANISH_D->GetBannedSites()) == -1) {
    return "You somehow managed to fail.  Nicely done.";
  }
  this_player()->eventPrint("Successfully sitebanned " + args + ".");
  return 1;
}
