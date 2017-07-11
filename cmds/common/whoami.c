/* 
 * For confused players with
 * too many different characters.
 */

mixed cmd() {
  return this_player()->GetKeyName(); 
}

string GetHelp(string blah) {
  return "Syntax: <whoami>\n\n"
         "This command will return the name of the player "
         "character you are currently using. Useful for those "
         "with several different characters, so they can "
         "remember who they are at the moment.";
}