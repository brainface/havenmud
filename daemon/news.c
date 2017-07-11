/*
 * The news daemon
 *
 * Written by Zaxan@Haven
 *
 */

#include <lib.h>
#include <news.h>
#include <daemons.h>

inherit LIB_DAEMON;

static void EndNews() {
    message("news", "", this_player());
    this_player()->eventDescribeEnvironment(0);
}

void NewbieNews() {
    if( file_exists(NEWS_NEWBIE) && newbiep(this_player())) {
	string news;

	news = read_file(NEWS_NEWBIE);
	message("news", "\n%^RED%^Newbie news:", this_player());
	message("news", news, this_player());
	message("prompt", "Press <return> to continue: ", this_player());
	input_to((: EndNews, "" :));
	return;
    }
    else EndNews();
}
