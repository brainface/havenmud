/*    /cmds/player/title.c
 *    from the Dead Souls LPC Library
 *    allows someone to set their titles
 *    created by Descartes of Borg 950716
 */

#include <lib.h>

inherit LIB_DAEMON;

static void eventOrderTitles(string *titles, int maxi);
static void GetTitle(string which, string *titles, int maxi);
static void GetDest(string which, string *titles, int i, int maxi);

mixed cmd(string args) {
    string *titles;
    int i, maxi;

    if( !(maxi = sizeof(titles = (string *)this_player()->GetRanks())) ) 
      return "You are without rank.";
    if (args == "norank") {
       if (this_player()->GetNoRank()) {
        this_player()->SetNoRank(0);
        this_player()->eventPrint("Your Social Rank will now be displayed.");
        return 1;
      }
      this_player()->SetNoRank(1);
      this_player()->eventPrint("You will not display your social rank.");
      return 1;
    }
    if( maxi == 1 ) {
	    message("system", "You have only one rank: " + titles[0], this_player());
	    return 1;
    }
    else if( maxi == 2 ) {
	    function f;

	    f = function(string yn, string *titles) {
	      yn = (yn || "n");
	      if( yn != "y" ) {
		     message("system", "Ranks remain unchanged.", this_player());
		     return;
	      }
	      this_player()->SetRanks( ({ titles[1], titles[0] }) );
	      message("system", "Ranks reversed.", this_player());
	    };
	  message("system", "You have the following ranks:\n\t" +
		  titles[0] + "\n\t" + titles[1], this_player());
	  message("prompt", "Do you wish to reverse them? [n] ", this_player());
	  input_to(f, titles);
	  return 1;
    }
    else eventOrderTitles(titles, maxi);
    return 1;
}

static void eventOrderTitles(string *titles, int maxi) {
    int i;

    message("system", "You have the following ranks:", this_player());
    for(i=0; i<maxi; i++)
      message("system", "\t" + (i+1) + " " + titles[i], this_player());
    message("prompt", "Move which (q to quit)? [" + (maxi) + "] ", 
	    this_player());
    input_to((: GetTitle :), titles, maxi);
}

static void GetTitle(string which, string *titles, int maxi) {
    int x;

    if( which == "q" ) {
	this_player()->SetRanks(titles);
	message("system", "Done.", this_player());
	return;
    }
    else if( which == "" || !which ) which = "" + maxi;
    x = to_int(which);
    if( x < 1 || x > maxi ) {
	message("system", "Illegal rank number.", this_player());
	eventOrderTitles(titles, maxi);
	return;
    }
    x--;
    message("prompt", "Move \"" + titles[x] + "\" to position? [1] ",
	    this_player());
    input_to( (: GetDest :), titles, x, maxi );
}

static void GetDest(string which, string *titles, int i, int maxi) {
    string *tmp;
    int j, maxj, x;

    if( which == "q" ) {
	this_player()->SetRanks(titles);
	message("system", "Done.", this_player());
	return;
    }
    else if( which == "" || !which ) which = "1";
    x = to_int(which);
    if( x < 1 || x > maxi || x == i+1 ) {
	message("system", "Illegal ranks number.", this_player());
	eventOrderTitles(titles, maxi);
	return;
    }
    x--;
    tmp = allocate(maxj = sizeof(titles));
    for(j=0; j<maxj; j++) {
	if( j == x ) tmp[j] = titles[i];
	else if( (j < x && j < i) || (j > x && j > i) ) tmp[j] = titles[j];
	else if( j > x && j <= i ) tmp[j] = titles[j-1];
	else tmp[j] = titles[j+1];
    }
    eventOrderTitles(tmp, maxi);
}

string GetHelp(string useless) {
   return "Syntax: <rank>\n\n"
		"Allows you to reorder your ranks.  Your first rank "
		"appears in your short description.  This command is "
		"interactive, meaning it prompts you for what to do.  "
		"hit 'q' at any point to save your changes and exit out of "
    "this command.\n"
    "Use can use \"rank norank\" to hide any social rank you may have achieved. \n"
    "Using rank norank again will undo that change.";
    
}

