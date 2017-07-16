#include <daemons.h>

mixed cmd(string args) {
  if(!args) {
    return ("Correct syntax: unsiteban <ip>\n");
    }
  BANISH_D->RemoveBannedSite(args);
  if (member_array(args, BANISH_D->GetBannedSites()) != -1) {
    return "You somehow managed to fail.  Nicely done.";
  }
  this_player()->eventPrint("Successfully unsitebanned " + args + ".");
  return 1;
}
