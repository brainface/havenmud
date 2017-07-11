/*  /cmds/player/date.c
 *  A simple command which displays current date and time
 *  Blitz@NM-IVD
*/
 
#include <lib.h>
#include <daemons.h>
#include <localtime.h>
 
mixed cmd(string unused) {
  message("system", "Server Time: " + ctime(time()), this_player() );
  message("system", "Kailie Time: "       + mtime(time()), this_player() );
  return 1;
}
 
string GetHelp(string u) {
  return  "Syntax: date\n\n"
          "Displays current time and date for both Kailie and Duuk (server time).";
}
