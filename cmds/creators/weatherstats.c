#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
    this_player()->eventPrint(mtime(time()));
    WEATHER_D->eventReportNumbers(this_player());
    return 1;
 }
